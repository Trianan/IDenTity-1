/*
	<------ -= ======------ -= ======------ -= ======>  H O U S E  L E D G E R  <=======------ -= ======------ -= ======------ -= ======------->
						* * * * + + + + * * * * + + + + * * * * + + <$> * * + + + + * * * * + + + + * * * * + + + +
								<------ -= ======------ -= ======------ -= ======------ -= ======------->
															By: Trianan
														Created: Dec 26/2021
													 __________________________

								A program made to manage shared expenses and debts between housemates.



	<------ -= ======------ -= ======------ -= ======-------> NOTES & TO-DO <------ -= ======------ -= ======------ -= ======------->

							- Figure out a good method for paying off an amount of household balance 
							  automatically when paying off debt owed to another housemate from a 
							  household expense. (Dec 26/2021)

							- Need to create test program. (Dec 26/2021)

							- Transaction history for both Accounts and Houses, stored on files. (Dec 26/2021) [1/2]

							- User interface implementation, including login and password protection. (Dec 27/2021)

							- House can inherit a lot from Account; should probably refactor that. (Dec 27/2021)

								> House can literally be an Account with extra privledges, 
								  therefore refactoring Account to include members for House accounts, and getting rid of the class House is probably
								  the move. (Dec 30/2021) 

							

	<------ -= ======------ -= ======------ -= ======-------> CHANGELOG <------ -= ======------ -= ======------ -= ======------->

							- Verification that a buyer is a resident when adding a household expense implemented. (Dec 26/2021)

							- Transaction struct implemented. (Dec 26/2021)

							- Transaction history exporting to text files mplemented for Accounts. (Dec 27/2021)

*/

// < ------ -= ======------ -= ======------> P R E P R O C E S S O R <------ -= ======------ -= ======------->

// Headers and libraries:
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

// Using directives & aliases:
using namespace std;


// <------ -= ======------ -= ======------> D E C L A R A T I O N S <------ -= ======------ -= ======------->

// Classes:
class Account;

// Functions:
string get_current_date();

// Objects & Constants:
hash<string> hash_str;






/* <------ -= ======------ -= ======------> C L A S S E S <------ -= ======------ -= ======------->
	  * * * * + + + + * * * * + + + + * * * * + + <O> * * + + + + * * * * + + + + * * * * + + + + 
    <------ -= ======------ -= ======------> TRANSACTION <------ -= ======------ -= ======-------> */

struct Transaction { // Represents a single transaction between two accounts; includes a timestamp.
	double amount = 0.0;
	string date = "yyyy/mm/dd";
	string payer = "payer_name";
	string payee = "payee_name";

	Transaction(double n, string pr, string pe);
	void print() {
		if (amount > 0.0)
			cout << payer << " paid " << payee << " on " << date << " $" << amount << '\n';
		if (amount < 0.0)
			cout << payer << " borrowed from " << payee << " on " << date << " $" << amount << '\n';
		return;
	}
};
Transaction::Transaction(double n, string pr, string pe)
	: amount(n), payer(pr), payee(pe), date(get_current_date()) {};

void print_transaction_history(string history_owner, vector<Transaction>& t_hist, ostream& os=cout) {
	cout << history_owner << "'s transaction history as of "<<get_current_date()<<":\n";
	for (int i = 0; i<t_hist.size(); ++i) {
		cout << "\t ->" << i + 1 << " (" << t_hist[i].date << "): $" << t_hist[i].amount
			<< "\tPayer: " << t_hist[i].payer << "\tPayee: " << t_hist[i].payee << '\n';
	}
	cout << '\n';
	return;
}

// <------ -= ======------ -= ======------> ACCOUNT <------ -= ======------ -= ======------->

class Account { // Represents a single housemate and their stats.
public:
	Account(string n, string pswd, bool is_h, string h="homeless");

	void create_transaction(Account recipient, double amount);

	string get_name() { return name; }
	double get_total_balance() { return total_balance; }
	Account get_housemate(int i) { return housemates[i]; }
	double get_balance(int i) { return balances[i]; }
	int get_housemate_count() { return housemates.size(); }

	void modify_balance(string housemate, double amount, bool household=false);
	void list_housemates(ostream& os=cout);
	void add_housemate(Account h);
	void print_stats(bool export_stats=false);
	void reset_passwd(string old_passwd, string new_passwd);

	// House account priviledges:
	void add_house_expense(double amount, string buyer_name);

private:
	string name = "!"; // Name of owner of balance.
	size_t password;

	string house_name;
	double house_balance; // Accounts individual balance towards their house; not used if account IS a house.
	bool is_house; 

	double total_balance = 0; // Negative balance is net debt.
	vector<Transaction> transaction_history;

	vector<Account> housemates; // Names of debtors and borrowers.
	vector<double> balances; // Negative balances are debts, order is tied to vector "housemates".

	bool existing_housemate(string name); // Checks if a given name is owed by an existing housemate.
	char prompt_new_housemate(string h_name); // Prompts the user to add a new housemate.
};
Account::Account(string n, string pswd, bool is_h, string h ) : name(name), is_house(is_h), house(h) {
	password = hash_str(pswd);
};

void Account::create_transaction(Account recipient, double amount) {
	for (int i = 0; i < housemates.size(); ++i) {
		// If transaction is between individual housemates...
		if (recipient.get_name() == housemates[i].get_name()) {
			// ...modify both accounts' balances.
			housemates[i].modify_balance(name, amount, false);
			modify_balance(housemates[i].get_name(), amount *= -1, false);
		}
		// If transaction is a shared household cost...
		else if (recipient.get_name() == house_name && recipient.is_house) {
			// ...divide the cost between residents...
			double resident_cost = amount / recipient.get_housemate_count();
			// ...modify balance in favour of the house...
			recipient.modify_balance(name, (amount - resident_cost), true);

			for (int i = 0; i < recipient.get_housemate_count(); ++i) {
				Account resident = recipient.get_housemate(i);
				if (resident.get_name() != name) {
					// ...modify the balance of each non-buyer housemate as a cost.
					resident.modify_balance(house_name, resident_cost * -1, true);
				}
			}
		}
	}
}
void Account::modify_balance(string h_name, double amount, bool household = false) {
	for (int i = 0; i < housemates.size(); ++i) {
		if (housemates[i].get_name() == h_name || house_name == h_name) {

		}



	}
}

// Helpers:
bool Account::existing_housemate(string name) {
	for (int i = 0; i < housemates.size(); ++i) {
		if (name == housemates[i].name)
			return true;
	}
	return false;
}
char Account::prompt_new_housemate(string h_name) {
	cout << h_name << " is not an existing housmate! Add as a new housemate? (y/n): ";
	char input = '!';
	while (input != 'n') {
		if (input == 'y') {
			Account new_account{ h_name };
			add_housemate(new_account);
			cout << "\t" << housemates[housemates.size() - 1].name << " was added as a housemate!\n";
			return input;
		}
	}
	return input;
}
// Member modifying:
void Account::add_housemate(Account h) {
	for (int i = 0; i < housemates.size(); ++i) {
		if (existing_housemate(h.name)) {
			cout << "Cannot add " << h.get_name() << " to " << name << "'s housemates: name already taken!\n";
			return;
		}
		else {
			housemates.push_back(h);
			balances.push_back(0.0);
			cout << h.get_name() << " added to " << name << "'s housemates.\n";
		}
	}
	return;
}
void Account::reset_passwd(string old_passwd, string new_passwd) {
	if ((hash_str(old_passwd) == password) {
		cout << "Password successfully reset!\n";
			password = new_passwd;
			return;
	}
	else {
		cout << "Incorrect password! Try again? (y/n): ";
			char c; cin >> c;
			if (c == 'y') {
				cout << "\n Old Password: ";
					string o_pswd; cin >> o_pswd;
					cout << "\nNew password: ";
				string n_pswd; cin >> n_pswd;
				reset_passwd(o_pswd, n_pswd);
			}
		if (c == 'n') {
			cout << "Cancelling password reset...\n";
			return;
		}
	}
}

















// Member displaying:
void Account::list_housemates(ostream& os = cout) {
	os << name << "'S HOUSEMATES: \n\tListing " << name << "'s borrowers: \n";
	for (int i = 0; i < housemates.size(); ++i) {
		if (balances[i] > 0.0) {
			os << fixed << setprecision(2) << "\t\t- "
				<< housemates[i].name << " owes: $" << balances[i] << '\n';
		}
	}
	os << "\n\tListing " << name << "'s debtors: \n";
	for (int i = 0; i < housemates.size(); ++i) {
		if (balances[i] < 0.0) {
			os << fixed << setprecision(2) << "\t\t- "
				<< housemates[i].name << " is owed : $" << balances[i] << '\n';
		}
	}
	os << "\n\t" << name << " is even with: \n";
	for (int i = 0; i < housemates.size(); ++i) {
		if (balances[i] == 0.0) {
			os << "\t\t- " << name << " is even with " << housemates[i].name << ".\n";
		}
	}
	return;
}
void Account::print_stats(bool export_stats = false) {
	if (export_stats) {
		string filename = name + "_stats_" + get_current_date() + ".txt";
		ofstream ofs{ filename };
		ofs << name << "'s STATS:\n";
		list_housemates(ofs);
		ofs << name << "'s current total balance : " << total_balance << '\n';
		print_transaction_history(name, transaction_history, ofs);
	}
	else {
		cout << name << "'s STATS:\n";
		list_housemates();
		cout << name << "'s current total balance : " << total_balance << '\n';
		print_transaction_history(name, transaction_history);

	}
}




// <-------=======------ -= ======------> STORAGE <------ -= ======------ -= ======------->


// <------ -= ======------ -= ======------> UI <------ -= ======------ -= ======------->

class UI {
public:
	void login();
	void logout();
	char prompt_command();

private:
	Account current_user;
	vector<Account> accounts;

	void load_accounts(string filename);
	void create_transaction();
	void view_stats();
	void save_stats();
	void list_housemates();

	Account valid_account(string account_name);

	char create_transaction_cmd = 'c';
	char view_stats_cmd = 'v';
	char list_housemates_cmd = 'l';

};

Account UI::valid_account(string account_name) {
	// Returns an existing account if one matches the given name.
	for (Account existing_account : accounts)
		if (account_name == existing_account.get_name())
			return existing_account;
	cout << "Invalid account name: " << account_name << "\nPlease re-enter: ";
	cin >> account_name;


}


void UI::login() {
	cout << "LOGIN\n\tAccount name: ";
	string account_name; cin >> account_name;

}
void UI::logout() {

}



/* <------ -= ======------ -= ======------> F U N C T I O N S < ------ -= ======------ -= ======------->
	   * * * * + + + + * * * * + + + + * * * * + + <O> * * + + + + * * * * + + + + * * * * + + + +
	<------ -= ======------ -= ======------> SYSTEM INFO < ------ -= ======------ -= ======-------> */

string get_current_date() {
	stringstream ss;
	auto t = std::time(nullptr); // https://en.cppreference.com/w/cpp/io/manip/put_time#Format_string
	auto tm = *std::localtime(&t);
	ss << put_time(&tm, "%Y-%m-%d : %H-%M-%S") << endl; // Sets current date and time in descending format.
	return ss.str();
}

// <------ -= ======------ -= ======------> M A I N <------ -= ======------ -= ======------->

int main() {

	return 0;
}

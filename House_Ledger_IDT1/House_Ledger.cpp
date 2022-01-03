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
							  household expense. (Dec 26/2021 - Trianan)

							- Need to create test program. (Dec 26/2021 - Trianan)

							- Transaction history for both Accounts and Houses, stored on files. (Dec 26/2021 - Trianan) [1/2]

							- User interface implementation, including login and password protection. (Dec 27/2021 - Trianan)

							- House can inherit a lot from Account; should probably refactor that. (Dec 27/2021 - Trianan)

								> House can literally be an Account with extra privledges, 
								  therefore refactoring Account to include members for House accounts, and getting rid of the class House is probably
								  the move. (Dec 30/2021 - Trianan) 

							- hi tristin (Jan 1/2022 - Ash)

							- Implement saving to files for BalanceTable date, and automatically loading the 
							  last logged-in BalanceTable upon startup of UI, if there was one. (Jan 2/2022 - Trianan)

						
	<------ -= ======------ -= ======------ -= ======-------> CHANGELOG <------ -= ======------ -= ======------ -= ======------->

							- Verification that a buyer is a resident when adding a household expense implemented. (Dec 26/2021 - Trianan)

							- Transaction struct implemented. (Dec 26/2021 - Trianan)

							- Transaction history exporting to text files mplemented for Accounts. (Dec 27/2021 - Trianan)

							- Major refactoring. (Dec 30/2021 - Trianan)

							- Gutted program almost entirely and restarted with BalanceTable concept and 
							  different stucture in general. House and associated code removed. (Dec 31/2021 - Trianan)

							- Gutted program again with different structure. (Jan 1/2021 - Trianan)

							- Fleshed out the Account and BalanceTable classes; more
							  bool-returning functions used for simplifying the UI implementation.
							  Started development on UI. (Jan 2/2021 - Trianan) 
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
struct Balance;
struct Transaction;

// Functions:
string get_current_date();

// Objects & Constants:
hash<string> hash_str;

int account_id_length = 8;
int ascii_table_length = 127;
string default_password = "default";
string default_ui_save = "ui_save.txt";


/* <------ -= ======------ -= ======------> C L A S S E S <------ -= ======------ -= ======------->
	  * * * * + + + + * * * * + + + + * * * * + + <O> * * + + + + * * * * + + + + * * * * + + + + 
	  
   <------ -= ======------ -= ======------> ACCOUNT < ------ -= ======------ -= ======-------> */
class Account {
	// Represents an individual.
public:
	Account(string nm, string pswd);
	bool operator == (Account& other); // Checks accounts IDs.

	string name_str() { return name; }
	string get_id() { return account_id; }
	void change_name(string new_nm) { name = new_nm; }
	bool change_password(string old_pswd, string new_pswd);
	bool is_password(string pswd) {
		if (hash_str(pswd) == password) return true;
		else return false;
	}
	double net_balance();
	bool existing_holder(Account& holder);
	bool add_balance_holder(Account& holder);
	bool change_balance(Account& holder, double amount);
	void record_transaction(Transaction t) { transaction_history.push_back(t); }

private:
	string name; // Name of owner.
	size_t password; // Owner's login purposes.
	string account_id = ""; // IDs accounts while allowing for name changes.

	vector<Balance> balances; // Contains info on debts/credits towards other accounts.
	vector<Transaction> transaction_history;

};
Account::Account(string nm, string pswd)
	: name(nm) {
	// Stores hash of password:
	password = hash_str(pswd);
	// Generates a random account ID upon initialization:
	srand(time(NULL));
	for (int i = 0; i < account_id_length; ++i) {
		char c = rand() % ascii_table_length + 1;
		account_id += c;
	}
}
bool Account::operator== (Account& other) {
	if (account_id == other.account_id)
		return true;
	else return false;
}
// Core functions:
bool Account::add_balance_holder(Account& holder) {
	if (!existing_holder(holder)) {
		Balance new_balance{ holder, 0.0 };
		balances.push_back(new_balance);
		return true;
	}
	return false;
}
bool Account::change_balance(Account& holder, double amount) {
	if (existing_holder(holder)) {
		for (Balance existing : balances)
			if (existing.holder == holder) {
				existing.amount += amount;
				return true;
			}
		return false;
	}
}
// Helpers:
bool Account::change_password(string old_pswd, string new_pswd) {
	// Changes the password if the old password given is correct:
	if (is_password(old_pswd)) {
		password = hash_str(new_pswd);
		return true;
	}
	else
		return false;
}
double Account::net_balance() {
	// Returns the net balance of an individual account (negative is debt).
	double net = 0.0;
	for (Balance balance : balances)
		net += balance.amount;
	return net;
}
bool Account::existing_holder(Account& holder) {
	for (Balance balance : balances)
		if (balance.holder == holder)
			return true;
	return false;
}


// <------ -= ======------ -= ======------> TRANSACTION < ------ -= ======------ -= ======------->
struct Transaction {
	// A record of a transaction between two accounts.
	Transaction(Account& a, Account& b, double amnt, bool shrd=false);
	const Account& from;
	const Account& to;
	const double amount;
	const string date = get_current_date();
	const bool shared;
};
Transaction::Transaction(Account& a, Account& b, double amnt, bool shrd)
	: from(a), to(b), amount(amnt), shared(shrd) {}


// <------ -= ======------ -= ======------> BALANCE < ------ -= ======------ -= ======------->
struct Balance {
	// Represents the balance held by another account.
	Balance(Account& hldr, double amnt = 0.0);
	Account& holder; // Person is owes/is owed an amount.
	double amount;

};
Balance::Balance(Account& hldr, double amnt)
	: holder(hldr), amount(amount) {};


// <------ -= ======------ -= ======------> BALANCE TABLE < ------ -= ======------ -= ======------->
class BalanceTable {
	// Represents the balances between all participents.
public:
	BalanceTable(string nm, string filename);
	BalanceTable(string nm, string filename, vector<Account&> starting_accounts);
	bool existing_account(Account& account);
	bool add_account(Account& account);
	bool modify_balance_entry(Account& account, Account& holder, double amount);
	bool create_transaction(Account& from, Account& to, double amount, bool shared=false);
	bool distribute_cost(Account& buyer, double amount, vector<Account&> omissions = vector<Account&>{});
	void record_shared_transaction(Transaction t) { shared_transaction_history.push_back(t); }

private:
	string name; // Name of group on table.
	string savefile; // File used to save and pull data from.
	vector<Account&> accounts; // References to each associated account.

	Account table_account;
	vector<Transaction> shared_transaction_history;

};
BalanceTable::BalanceTable(string nm, string filename)
	: name(nm), savefile(filename), table_account(Account{ nm,default_password }) {};
BalanceTable::BalanceTable(string nm, string filename, vector<Account&> starting_accounts)
	: name(nm), savefile(filename), table_account(Account{ nm,default_password }), accounts(starting_accounts) {};
// Core functions:
bool BalanceTable::create_transaction(Account& a, Account& b, double amount, bool shared) {
	/* Modifies the correct entriesand generates a transaction entry between two accounts:
		- Positive amounts are credits owed to 'a' by 'b'.
		- Negative amounts are debts owed to 'b' from 'a'.
		- Credits for 'a' correspond to debts from 'b', and vica-versa.
	*/
	if (existing_account(a) && existing_account(b)) {
		// From 'a' to 'b':
		modify_balance_entry(a, b, amount);
		a.record_transaction(Transaction{ a,b,amount,shared });
		// From 'b' to 'a':
		modify_balance_entry(b, a, -amount);
		b.record_transaction(Transaction{ b,a,-amount,shared });
		return true;
	}
	return false;
}
bool BalanceTable::distribute_cost(Account& buyer, double amount, vector<Account&> excluded_accounts) {
	/* Distributes a given cost or credit evenly amongst sharers:
		- Generates individual transactions between buyer and sharers.
		- Cost for each sharer is calculated by (net cost)/(# of sharers).
		- Transactions are marked as shared costs/credits.
	*/
	if (existing_account(buyer)) {
		double individual_cost = amount / (accounts.size() - excluded_accounts.size());
		excluded_accounts.push_back(buyer);
		record_shared_transaction(Transaction{ buyer, table_account, amount, true });

		for (Account& sharer : accounts) { // Checks if account is excluded:
			bool included = true;
			for (Account& excluded_account : excluded_accounts)
				if (sharer == excluded_account)
					included = false;
			if (included)
				create_transaction(buyer, sharer, individual_cost); // Generates pair of transactions between buyer and sharer.
		}
		return true;
	}
	return false;
}
// Helpers:
bool BalanceTable::existing_account(Account& account) {
	// Checks if an account is on the table already.
	for (Account& existing : accounts)
		if (existing.get_id() == account.get_id())
			return true;
	return false;
}
bool BalanceTable::add_account(Account& account) {
	// Adds an account to the table, and adds to the account a balance 
	// for each account on the table.
	if (!existing_account(account)) {
		for (Account& existing : accounts)
			account.add_balance_holder(existing);
		accounts.push_back(account);
		return true;
	}
	return false;;
}
bool BalanceTable::modify_balance_entry(Account& account_owner, Account& holder, double amount) {
	// Modifies an existing account's balance with another account.
	if (existing_account(account_owner) && account_owner.existing_holder(holder)) {
		account_owner.change_balance(holder, amount);
		return true;
	}
	return false;
}


// <------ -= ======------ -= ======------> UI < ------ -= ======------ -= ======------->
class UI {
public:
	UI();

private:
	string savefile;
	BalanceTable& current_table;
	Account& current_user;
};
UI::UI()
	: savefile(default_ui_save) {
	ifstream last_table{ savefile };
	if (last_table) {
		
	}
}

/* <------ -= ======------ -= ======------> F U N C T I O N S < ------ -= ======------ -= ======------->
	   * * * * + + + + * * * * + + + + * * * * + + <O> * * + + + + * * * * + + + + * * * * + + + +
	    
	<------ -= ======------ -= ======------> SYSTEM INFO < ------ -= ======------ -= ======-------> */
string get_current_date() {
	stringstream ss;
	auto t = std::time(nullptr); // https://en.cppreference.com/w/cpp/io/manip/put_time#Format_string (Dec 27/2021 - Trianan)
	auto tm = *std::localtime(&t);
	ss << put_time(&tm, "%Y-%m-%d : %H-%M-%S") << endl; // Sets current date and time in descending format. (Dec 27/2021 - Trianan)
	return ss.str();
}


// <------ -= ======------ -= ======------> M A I N <------ -= ======------ -= ======------->

int main() {

	return 0;
}

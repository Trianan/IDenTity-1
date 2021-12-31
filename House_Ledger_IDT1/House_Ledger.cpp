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

							

	<------ -= ======------ -= ======------ -= ======-------> CHANGELOG <------ -= ======------ -= ======------ -= ======------->

							- Verification that a buyer is a resident when adding a household expense implemented. (Dec 26/2021 - Trianan)

							- Transaction struct implemented. (Dec 26/2021 - Trianan)

							- Transaction history exporting to text files mplemented for Accounts. (Dec 27/2021 - Trianan)

							- Major refactoring. (Dec 30/2021 - Trianan)

							- Gutted program almost entirely and restarted with BalanceTable concept and 
							  different stucture in general. (Dec 31/2021 - Trianan)

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
	  
   <------ -= ======------ -= ======------> BALANCE TABLE < ------ -= ======------ -= ======-------> */
class BalanceTable { // Represents current balances with all associated accounts; does not belong to any one account. (Dec 31/2021 - Trianan)
public:
	BalanceTable(vector<Account>& accounts);
	void modify_balance(Account& account_owner, Account& balance_holder, double amount);
	void distribute(double amount, vector<Account>& accounts);
	void print(ostream& os = cout);
private:
	vector<Account&> account_owners;


	
};
BalanceTable::BalanceTable(vector<Account>& accounts)
	: balance_holders(accounts) {};

void BalanceTable::modify_balance(Account& account_owner, Account& balance_holder, double amount) {
	for (Account& acc : account_owners)
		if (account_owner == acc) { // Checks if account_owner is on the table...
			for (int i = 0; i < account_owner.holder_count(); ++i) { //...then checks the owner's balance holders.
				if (account_owner.get_holder(i) == balance_holder) {
					account_owner.balance_amounts[i] += amount; // Modifies the balance of matching balance owner.
				}
			}
		}
	return;
}
void BalanceTable::distribute(double amount, vector<Account>& accounts) {

	return;
}

// <------ -= ======------ -= ======------> ACCOUNT <------ -= ======------ -= ======------->
class Account { // Represents the financial status of a single person. (Dec 31/2021 - Trianan)
public:
	Account(string nm, string pswd, BalanceTable& bt);
	bool operator==(Account& account);

	void create_transaction(double amount, Account& account_to);

	string get_name() { return name; }
	double get_holder_balance(Account& holder);
	int holder_count() { return balance_holders.size(); }
	Account& get_holder(int i) { return balance_holders[i]; }


	vector<double> balance_amounts; // Balance for each holder. (Dec 31/2021 - Trianan)

private:
	string name; // Name of account. (Dec 31/2021 - Trianan)
	string password; // Password for login. (Dec 31/2021 - Trianan)

	double total_balance = 0; // Sum of all balances. (Dec 31/2021 - Trianan)
	vector<Account&> balance_holders; //  Each account on BalanceTable is a holder except this account.
	BalanceTable& balances;
	vector<Transaction> transaction_history; // This account's transaction history; populated in chronological order. (Dec 31/2021 - Trianan)
};
Account::Account(string nm, string pswd, BalanceTable& bt)
	: name(nm), password(pswd), balances(bt) {};
bool Account::operator==(Account& account) {
	if (name == account.get_name())
		return true;
	else 
		return false;
}

void Account::create_transaction(double amount, Account& account_to) {

}
double Account::get_holder_balance(Account& holder) {
	for (int i = 0; i < balance_holders.size(); ++i) {
		if (holder == balance_holders[i]) {
			return balance_amounts[i];
		}
		else return 0.0;
	}
}


//  <------ -= ======------ -= ======------> TRANSACTION <------ -= ======------ -= ======-------> 
struct Transaction { // Represents a single transaction between two accounts; includes a timestamp. (Dec 28/2021 - Trianan)
	Transaction(double n, Account pr, Account pe); // For transactions between two individuals. (Dec 31/2021 - Trianan)
	Transaction(double n, Account buyer, vector<Account>&accounts); // For shared expenses/transactions. (Dec 31/2021 - Trianan)

	double amount = 0.0;
	string date = "yyyy/mm/dd";
	Account payer;
	Account payee;
	// These two are for shared expenses only:			(Dec 31/2021 - Trianan)
	bool is_shared = false;
	vector<Account> accounts;
};
Transaction::Transaction(double n, Account pr, Account pe)
	: amount(n), payer(pr), payee(pe), date(get_current_date()) {};
Transaction::Transaction(double n, Account buyer, vector<Account>&accs)
	: amount(n), payer(buyer), accounts(accs), is_shared(true) {};









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


/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  E U L E R  T O O L S  <=======------ -= ======------ -= ======------ -= ======------->

		EULERTOOLS: A set of tools developed for Project Euler problems.

			- class BigNum: a type developed for integers outside the range of standard integer types.

	< ------ -= ======------ -= ======------ -= ======------ -= ======-------> N O T E S <------ -= ======------ -= ======------ -= ======------ -= ======------->

			- Initial version of BigNum created (Dec 17/2021).
			- BigNum initializer further developed, with intention of creating representation as a stream.
			  Also worked on add() function for BigNum (Dec 18/2021).


	*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace EulerTools {

	string non_init_str = "\n\t\t* ! * UNINITIALIZED STRING * ! *\n";

	// BIGNUM:
	class BigNum {
	public:
		BigNum(string n_filename);
		BigNum add(BigNum& a, BigNum& b);
	private:
		string n_string = non_init_str;
		vector<int> digits;
	};

	BigNum::BigNum(string n_filename) {
		// Reading number from text file into a cleaned-up string.
		ifstream n_stream{ n_filename };
		if (!n_stream) {
			cout << "File not found; please enter a new filename: ";
			cin >> n_filename;
			n_stream.close();
			n_stream.open(n_filename);
		}
		cout << "\nFile " << n_filename << " opened successfully.\n";
		// Cleaning up input:
		while (n_stream) {
			n_string = "";
			char c = '!';
			n_stream >> c;
			if (isdigit(c)) n_string += c;
		}
		cout << "n_string:\n\n" << n_string << '\n';
		stringstream n_stringstream{ n_string };
		// Reading digits into int-vector to create BigNum stream.
		while (n_stringstream)
			digits.push_back(n_stringstream.get());
		cout << "\nElements of 'digits': \n";
		for (int digit : digits) cout << digit << '\n';

		cout << "BigNum successfully initialized.\n";
	}
	BigNum BigNum::add(BigNum& a, BigNum& b) {

		int a_digits = a.digits.size();
		int b_digits = b.digits.size();
		int least_digits = (a_digits < b_digits) ? a_digits : b_digits;
		string sum_str = "";

		for (int i = 0; i <= least_digits; ++i) {
			int result = a.digits[a_digits - i] + b.digits[a_digits - i];
			// Need to figure out a way to carry and then properly adding to string instead
			// of just concatonating the results.

			BigNum sum{ sum_str };
			return sum;
		}
	}



	
















}
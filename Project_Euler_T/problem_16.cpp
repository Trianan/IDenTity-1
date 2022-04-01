/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #16: "Some Powerful Digits" - Trianan - Mar 31/2022

		   "2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

			What is the sum of the digits of the number 2^1000?"
    < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

string generate_expstr(string base, int exponent) { // This needs to be generalized for bases other than two; then added to EulerTools.

	// Generates a numstring for a giving base and exponent.
	string result = base;
	for (int i = 1; i < exponent; ++i) {
		vector<string> addends{ result, result };
		result = EulerTools::sum_addends(addends);
	}
	return result;
}

int sum_digits(string& numstring) {
    // Converts chars in numstring to ints, then sums them.
    int sum = 0;
    for (char c : numstring) {
        int digit = c - 48;
        sum += digit;
    }
    return sum;
}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {
    string n = generate_expstr("2", 1000);
    cout<<"\n\n\t2^1000 = "<<n<<"\n\n\tThe sum of it's digits is: "<<sum_digits(n)<<"\n\n";

    return 0;
}
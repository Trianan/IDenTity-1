/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #17: "English Sucks" - Trianan - Apr 1/2022

		   "If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
		    If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

		    NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
			The use of "and" when writing out numbers is in compliance with British usage.
		   "
    < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

vector<int> digits{ 1,2,3,4,5,6,7,8,9 };
vector<int>digit_lettercounts{ 3,3,5,4,4,3,5,5,4 };

int lettercount_tens(const int n) {
	// Function for getting the number of letters of english-spelled numbers less than 100.
	int lettercount = 0;
	// Handling numbers less than 20 has a much less obvious pattern:
	if (0 <= n && n < 20) {
		if (1 <= n && n < 13) {
			// The set of natural numbers under 13 has a strange naming pattern and each element must be considered individually.
			vector<int> n_under_13s{ 1,2,3,4,5,6,7,8,9,10,11,12 };
			vector<int> n_under_13_lettercounts{ 3,3,5,4,4,3,5,5,4,3,6,6 };

			for (int i = 0; i < n_under_13s.size(); ++i) {
				if (n == n_under_13s[i])
					lettercount = n_under_13_lettercounts[i];
			}
		}
		else if (13 <= n && n < 20) {
			// Handles "n-teen" naming convention.
			vector<int>teens{ 3,4,5,6,7,8,9 };
			vector<int>teen_prefix_lettercounts{ 4,4,3,3,5,4,4 }; // "thir", "four", "fif", ...

			for (int i = 0; i < teens.size(); ++i) {
				if (n - 10 == teens[i]) // Gets ones-digit of number e.g. 15-10=5 ---> "fif" ---> 3 letters.
					lettercount = teen_prefix_lettercounts[i] + 4; // + "teen".
			}
		}
	}

	// 20 <= n < 100 have a slightly more simple pattern, that is still distinct.
	else if (20 <= n && n < 100) {
		vector<int>tens{ 2,3,4,5,6,7,8,9 }; // n<20 has already been handled, so 1 is not included.
		vector<int>ten_prefix_lettercounts{ 4,4,3,3,3,5,4,4 }; // "twen", "thir", "for", ...

		for (int i = 0; i < tens.size(); ++i) {
			if (((n - (n % 10)) / 10) == tens[i]) { // (n - n-mod-10)/10 is going to be the digit in the tens place. e.g. 34-mod-10 = 4, 34-4 = 30, 30/10 = 3.
				lettercount = ten_prefix_lettercounts[i] + 2; // + "ty".

				if (n % 10 != 0) { // Handles numbers that are not integer multiples of 10.
					int ones_digit = n - (tens[i] * 10); // Get rid of the tens-place.
					for (int i = 0; i < digits.size(); ++i) {
						if (ones_digit == digits[i])
							lettercount += digit_lettercounts[i]; // "one", "two", ...
					}
				}
			}
		}
	}
	return lettercount;
}
int get_lettercount(const int n) {
	// Returns the number of letters in the British-spelling of a given integer (including convention for including "and").
	int lettercount = 0;

	if (n == 0) return 4;

	if (n < 100) {
		lettercount = lettercount_tens(n);
	}

	// These follow a simpler pattern; this also considers British convention of the word "and".
	else if (100<= n <= 9999) {

		for (int i = 0; i < digits.size(); ++i) {

			if ((n - n % 1000) / 1000 == digits[i]) // ("one", "two", ...) + "thousand".
				lettercount += digit_lettercounts[i] + 8;

			if ((n - n % 100) / 100 == digits[i]) {
				lettercount += digit_lettercounts[i] + 7; // ("one", "two", ... ) + "hundred".

				if (n % 100 != 0) { // If n is not an integer multiple of 100...
					int tens_ones = n - (digits[i] * 100); // Gets rid of 100s place.
					lettercount += (lettercount_tens(tens_ones) + 3); // + "and" + "thirty" + "one".
				}
			}
		}
	}
	return lettercount;
}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {

	while (true) {
		cout << "Number for lettercount: ";
		int n = 0; 
		if (cin >> n)
			cout << "# of letters in " << n << ": " << get_lettercount(n) << '\n';
		else break;
	}

	long long int ltrc = 0;

	for (int i = 1; i <= 1000; ++i) {
		ltrc += get_lettercount(i);
		cout << "\t\t\t" << i << " : " << ltrc << '\n';
	}
	cout << "\n\nLettercount 1-1000: " << ltrc << '\n';

    return 0;
}
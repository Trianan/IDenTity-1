/*
	Project Euler - Problem #10: "Some Primes" - Trianan - Oct 30/2021

		"The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
		Find the sum of all the primes below two million."
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void pause() {
	// Pauses execution until desired input given.
	cout << "\tPress any letter to continue: ";
	char input;
	while (true) {
		cin >> input;
		if (isalpha(input))
			break;
		else cout << "\t\tInput a letter!\n";
	}
}

int main() {
	long int max = 2000000;
	long long int sum = 0; // Must be long long int.

	const char prime = 'p';
	const char comp = 'c';

	vector<char> pattern(max, prime); // Index represents actual number; element refers to primality.
	pattern[0] = comp; pattern[1] = comp; // 0 and 1 are not prime.

	cout << "Running...\n";
	for (long int i = 2; i < max; ++i) {

		if (pattern[i] == prime) { // If i is indicated as a prime number...
			sum += i; // ...add i to sum.

			if (i<40 || i>1999800) // Displays starting and ending output only.
				cout << '\t' << i << " is a prime (" << pattern[i] << ")\n";

			for (long int m = 2; (i * m) < max; ++m)
				pattern[m * i] = comp;
		}
	}
	cout << "\n\t\t...finished.\n\tFinal sum --> " << sum << '\n';
}
/*
	Project Euler - Problem #3: "Largest Prime Factor" - Trianan - Oct 13/2021

		"The prime factors of 13195 are 5, 7, 13 and 29.
			What is the largest prime factor of the number 600851475143?"

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_prime(long long int n) {
	// Returns if a number is prime or not.
	for (int i = 2; i < n; ++i)
		if (n % i == 0) {
			cout << '\t' << n << '/' << i << '=' << (n / i) << '\n';
			n /= i;
			cout << "\t\t" << n << '\n'; // debugging purposes.
			return false;
		}
	return true;
}

void prime_factorize(long long int n, vector<long long int>& prime_factors) {
	// Returns the prime factors of a given number.
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			if (is_prime(n / i))
				prime_factors.push_back((n / i));
			n /= i;
		}
	}
}

int main() {
	vector <long long int> prime_factors;
	prime_factorize(600851475143, prime_factors);

	for (long long int pf : prime_factors)
		cout << "\t\t---> " << pf << '\n';
	
}
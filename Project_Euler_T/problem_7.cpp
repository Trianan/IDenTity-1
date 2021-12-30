/*
	Project Euler - Problem #7: "10,0001st prime" - Trianan - Oct 16/2021

		"By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
		we can see that the 6th prime is 13. What is the 10,001st prime number?"

*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool is_prime(long int n) {
	for (int i = 2; i < n; ++i)
		if (n % i == 0) return false;
	return true;
}

int main() {

	long int max_primes = 10001;
	vector<long int> primes;

	long int n = 2;
	while (primes.size() < max_primes) {
		if (is_prime(n)) {
			primes.push_back(n);
			cout << "\t-" << n << '\n';
		}
		++n;
	}
	cout << "Number of primes found: " << primes.size() << '\n'
		<<"First prime: "<<primes[0]<<'\n'
		<< "Last prime: " << primes[primes.size() - 1] << '\n';
}


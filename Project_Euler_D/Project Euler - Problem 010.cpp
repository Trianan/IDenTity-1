// Project Euler - Problem 010.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Summation of Primes"
// 
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	long long n = 2000000;
	long long sum = 0;
	vector<long long> prime(n, 1);

	for (long long i = 2; i < n; i++) {

		if (prime[i]) {

			long long j = pow(i, 2);

			while (j < n) {
				prime[j] = 0;
				j += i;
			}

			sum += i;
		}
	}

	cout << sum << endl;
}
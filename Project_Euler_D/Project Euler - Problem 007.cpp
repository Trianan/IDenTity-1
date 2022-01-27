// Project Euler - Problem 007.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "10001st Prime"
// 
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// 
// What is the 10 001st prime number ?

#include <iostream>

using namespace std;

bool prime(long long int x)
{

	if (x <= 1)
		return false;

	for (long long int i = 2; i <= x / 2; i++) {
		if (!(x % i)) {
			return false;
		}
	}

	return true;
}

int main()
{

	long long a = 10001;
	long long b = 0;
	long long i = 0;

	while (i < a) {

		if (prime(b)) {
			i += 1;
		}

		b += 1;
	}

	cout << b - 1 << endl;
}
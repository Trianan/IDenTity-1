// Project Euler - Problem 001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Multiples of 3 or 5"
// 
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int a = 0;
	int b = 0;

	while (a < 1000) {

		sum += a;
		a += 3;

	}

	while (b < 1000) {

		if (b % 3) {

			sum += b;

		}

		b += 5;

	}

	cout << sum << endl;
}

// Project Euler - Problem 009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Special Pythagorean Triplet"
// 
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// 
//															 a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// 
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long a = 1;

	while (a <= 292) {

		long b = (-2000 * a + 1000000) / (2000 - 2 * a);
		long c = sqrt(pow(a, 2) + pow(b, 2));

		if (a + b + c == 1000) {
			cout << a * b * c << endl;
		}

		a++;

	}
}

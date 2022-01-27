// Project Euler - Problem 015.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Lattice Paths"
// 
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the 
// bottom right corner.
//
// How many such routes are there through a 20×20 grid ?

#include <iostream>

using namespace std;

int main()
{

	unsigned long long sum;

	unsigned int n = 2;

	while (n <= 20)
	{
		sum = 1;

		for (unsigned int i = n + 1; i <= 2 * n; i++)
		{
			sum = sum * i;
			sum = sum / (i - n);
		}

		n++;
	}

	cout << sum;
}
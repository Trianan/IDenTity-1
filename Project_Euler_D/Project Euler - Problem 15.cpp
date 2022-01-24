// Project Euler - Problem 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
//
//
// How many such routes are there through a 20×20 grid ?

#include <iostream>

using namespace std;

int main()
{
	
	unsigned int n = 2;

	while (n <= 20)
	{
		unsigned long long sum = 1;

		for (unsigned int i = n + 1; i <= 2 * n; i++)
		{
			sum = sum * i;
			sum = sum / (i - n);
		}

		cout << sum << '\n';

		n++;
	}

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

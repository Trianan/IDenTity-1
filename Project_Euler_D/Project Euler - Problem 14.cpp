// Project Euler - Problem 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The following iterative sequence is defined for the set of positive integers:
//
// n -> n / 2 (n is even)
// n -> 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence :
//
// 13 -> 40 -> 20 -> 10 -> 5 → 16 -> 8 -> 4 -> 2 -> 1
// It can be seen that this sequence(starting at 13 and finishing at 1) contains 10 terms.Although it has not been proved yet(Collatz Problem), it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain ?
//
// NOTE : Once the chain starts the terms are allowed to go above one million.
//

#include <iostream>

using namespace std;

long long collatz_terms(long long n)
{
	long long count = 1;

	while (n > 1)
	{
		count++;

		if (!(n % 2))
		{
			n = n / 2;
		}

		else
		{ 
			n = 3 * n + 1;
		}
	}

	return(count);
}

int main()
{
	long long max_count = 0;

	long long solution = 0;

	for (long long i = 0; i < 1000000; i++)
	{
		if (collatz_terms(i) > max_count)
		{
			max_count = collatz_terms(i);
			solution = i;
		}
	}

	cout << solution;
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

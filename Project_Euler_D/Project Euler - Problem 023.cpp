// Project Euler - Problem 023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the 
// proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less than nand it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of 
// two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum
// of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the
// greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <iostream>
#include <vector>
#include <array>

using namespace std;

// function to check if a number is abundant
int is_abundant(int n)
{
	// initialize the sum of proper divisors
	int sum = 0;

	// check divisors from one to half of n
	// if modulus is 0, i is a divisor, and will be added to the sum
	for (int i = 1; i <= n / 2; i++)
	{
		if (!(n % i))
		{
			sum += i;
		}
	}

	// if the sum is greater than n, it is abundant
	if (sum > n)
	{
		return 1;
	}

	// otherwise, it is not abundant
	else
	{
		return 0;
	}
}

int main()
{
	// initialize a vector for abundant numbers
	vector<int> abundant_nums;

	// fill the vector with all abundant numbers between 12 and 28123 - 12
	for (int i = 12; i <= 28123 - 12; i++)
	{
		int j = 0;

		if (is_abundant(i))
		{
			abundant_nums.push_back(i);

			j++;
		}
	}

	// find how many entries are in the vector and store it as a variable
	int length = abundant_nums.size();

	// create an array that will eventually have a 1 if the value of the index is a sum of two abundant numbers, and a 0 otherwise
	int check[28123] = {0};

	// initialize the sum for the solution
	unsigned long long sum = 0;

	// find all possible sums for two abundant numbers under 28123, and mark their position in the "check" array with a 1
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (abundant_nums[i] + abundant_nums[j] > 28123)
			{
				break;
			}

			else
			{
				check[abundant_nums[i] + abundant_nums[j]] = 1;
			}
		}
	}

	// add together all indicies where the value is 0
	for (int i = 0; i < 28123; i++)
	{
		if (!check[i])
		{
			sum += i;
		}
	}

	//output solution
	cout << sum; 

	return 0;
}
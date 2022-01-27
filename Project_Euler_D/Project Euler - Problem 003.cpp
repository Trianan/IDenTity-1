// Project Euler - Problem 003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Largest Prime Factor"
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// 
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
using namespace std;

bool prime(long long int x)
{

	if (x <= 1)
		return false;

	for (long long int i = 2; i <= x / 2; i++) 
	{
		if (!(x % i)) 
		{
			return false;
		}
	}

	return true;
}

int main()
{

	long long int a = 600851475143;
	long long int lpf = 1;

	for (long long int i = 2; i <= a / 2;) 
	{

		if (prime(i) && !(a % i)) 
		{
			lpf = i;
			cout << lpf << endl;
		}

		i += 1;
	}
}

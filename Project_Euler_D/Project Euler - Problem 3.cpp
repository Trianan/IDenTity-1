// Project Euler - Problem 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	long long int a = 600851475143;
	long long int lpf = 1;

	for (long long int i = 2; i <= a / 2;) {

		if (prime(i) && !(a % i)) {
			lpf = i;
			cout << lpf << endl;
		}

		i += 1;
	}

	return 0;
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

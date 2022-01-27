// Project Euler - Problem 17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int number_of_letters(int x)
{
	int sum = 0;

	int a = x / 100;
	int b = x % 100;
	int c = b / 10;
	int d = x % 10;

	if (a == 1 || a == 2 || a == 6)
		sum = sum + 3;

	else if (a == 4 || a == 5 || a == 9)
		sum = sum + 4;

	else if (a == 3 || a == 7 || a == 8)
		sum = sum + 5;

	if (x >= 100)
	{
		sum = sum + 7;

		if (b)
			sum = sum + 3;

	}


	if (b == 10)
		sum = sum + 3;

	else if (b == 11 || b == 12)
		sum = sum + 6;

	else if (b == 13 || b == 14 || b == 18 || b == 19)
		sum = sum + 8;

	else if (b == 15 || b == 16)
		sum = sum + 7;

	else if (b == 17)
		sum += + 9;

	if (c == 2 || c == 3 || c == 8 || c == 9)
		sum += 6;

	else if (c == 4 || c == 5 || c == 6)
		sum += 5;

	else if (c == 7)
		sum += 7;

	if (c != 1)
	{
		if (d == 1 || d == 2 || d == 6)
			sum += 3;

		else if (d == 4 || d == 5 || d == 9)
			sum += 4;

		else if (d == 3 || d == 7 || d == 8)
			sum += 5;
	}

	return(sum);

}

int main()
{
	int sum = 11;

	for (int i = 1; i < 1000; i++)
	{
		sum += number_of_letters(i);
	}

	cout << sum;
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

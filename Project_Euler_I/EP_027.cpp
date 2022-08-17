// EP_27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int IsPrime(long num);


int main()
{
	int n = 0;
	cout << "how many primes do you want to know?" << endl;					//n = 168 shows all primes below 1000
	cin >> n;
	int* primes = new int[n];
	int pdex = 0;
	for (long i = 0; pdex < n; i++)
	{

		if (IsPrime(i + 1))
		{
			primes[pdex] = (i + 1);
			pdex++;
			cout << "prime number " << pdex << "is " << primes[pdex-1] << endl;
		}
	}

	for (int i = 0; i < n; i++) {
		if ((primes[i] * primes[i]) < 3988) {
			cout << primes[i] << " is a useable \"a\" value" << endl;
		}
	}
	delete[] primes;
}


int IsPrime(long num)						//returns 1 if num is prime, else, returns 0
{
	for (long i = 2; i < (num / 2); i++)
		if ((num % i) == 0)
		{
			return 0;
		}
	if ((num == 4) || (num == 1))
	{
		return 0;
	}

	return 1;
}
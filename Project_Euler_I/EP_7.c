// Isaiah Campsall		November 11, 2021		EP_7
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number ?

#include <stdio.h>
#include <stdlib.h>

int IsPrime(long num);

int main()
{
	printf("what nth prime number would you like to know?\n");
	long n = 0;
	scanf("%ld", &n);
	long* primes = (long*)malloc(n * sizeof(long));
	if (primes != NULL)
	{
		//long primes[10001] = { 0 };
		int pdex = 0;
		for (long i = 0; pdex < n; i++)
		{

			if (IsPrime(i + 1))
			{
				primes[pdex] = (i + 1);
				pdex++;
			}
		}
		
		printf("%2ld", primes[n - 1]);
		free(primes);
	}
	else
	{
		printf("failed to allocate memory");
	}
	return 0;
}

int IsPrime(long num)						//returns 1 if num is prime, else, returns 0
{
	for (long i = 2; i<(num/2); i++)
	if ((num % i) == 0)
	{
		return 0;
	}
	if ((num == 4) || (num ==1))
	{
		return 0;
	}

	return 1;
}
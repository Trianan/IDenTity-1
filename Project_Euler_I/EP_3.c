//Isaiah Campsall Oct. 15, 2021

#include <stdio.h>
#include <math.h>

int IsPrime(long long int number);

int main()
{
	long int primes[20];		//array of prime numbers in order
	int counter = 0;			//positional counter
	for (int i = 2; i < 1000; ++i)
	{

		if ((IsPrime(i) == 1) && (counter<20))
		{
			primes[counter] = i;
			counter++;
		}
	}



	long long int num = 600851475143;
	
	for (int p = 1; p < num; ++p)
	{
		if (((num % p) == 0) && (IsPrime(num / p) == 1))
		{
			printf("the largest prime factor of %lld is: %lld", num, (num / p));
			return 0;
		}
	}
}

int IsPrime(long long int number)
{
	for (int i = 2; i < number; ++i)
	{
		
		if ((number % i) == 0)		//"number" is not prime
		{
			return 0;
		}
	}
	return 1;		//"number" is prime
}
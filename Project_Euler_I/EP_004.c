/*Isaiah Campsall	October 21, 2021
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3 - digit numbers.
*/

#include <stdio.h>

long long int Rev(long long int fwrd);

long long int Rev(long long int fwrd)
{
	long long int sum = 0;
	while (fwrd >= 1)
	{
		sum = ((fwrd % 10) + (sum * 10));
		fwrd /= 10;
	}
	return sum;
}


int main()	//begin main function
{
	long long int bigPal = 0;
	long long int prod = 0;		//contains the product
	for (int i = 999; i > 99; --i)
	{
		for (int b = 999; b > 99; --b)
		{
			prod = (long long int)i * (long long int)b;
			if ((prod == Rev(prod)) && (prod > bigPal))
			{
				bigPal = prod;
			}
		}
	}

	printf("The largest palindromic product of two 3-digit numbers is: %lld", bigPal);


	return 0;
}
/*Isaiah Campsall		October 21, 2021
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <stdio.h>

int IsDiv(long int n);
int IsDiv(long int n)
{
	const static long int x = n;

	for (long int i = 2; i < x; ++i)
	{
		if ((n % i) != 0)
		{
			return 0;
		}

	}
	return 1;
}

int main()
{

	long int n = 0;
	scanf("%d", &n);
	long int x = n;
	while(!IsDiv(n))
	{
		n += x;
	}
	printf("%d", n);
}
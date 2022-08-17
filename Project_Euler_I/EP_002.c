//Isaiah Campsall Oct. 15, 2021

#include <stdio.h>

int IsOdd(int number);

int main()
{
	long int fibSeq[34];
	fibSeq[0] = 1;
	fibSeq[1] = 1;
	long long int sum = 0;

	for (int i = 2; i < 34; ++i)
	{
		fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
		if (IsOdd(fibSeq[i]) == 0)
		{
			sum += fibSeq[i];
		}
	}
	printf("the sum of even numbers in the fibannacci sequence when the individual values are still below 4 million is:\n %lld", sum);
}

int IsOdd(int number)		//"IsOdd" function determines if an inputs number is even or odd
{
	if ((number % 2) == 0)		//if the remainder of the input divided by 2 is 0, the number is even; return 0
	{
		return 0;
	}
	else						//else return 1 for odd
	{
		return 1;
	}
}
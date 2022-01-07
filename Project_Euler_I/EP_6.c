//Isaiah Campsall		Nov. 11, 2021		EP_6

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <stdio.h>


int main()
{
	int sum = 0;
	int sqr = 0;
	for (int i = 1; i < 101; i++)
	{
		sum += i;

		sqr += i * i;
	}
	sum = sum * sum;

	printf("the square of sums is: %d\nthe sum of squares is: %d\nthe difference between the two is:%d\n", sum, sqr, (sqr - sum));
}
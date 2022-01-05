//Isaiah Campsall Oct. 15, 2021

#include <stdio.h>

int main()
{
	long long int sumOf = 0;		//holds the sum of all multiples of 3 or 5
	long int numbers[1000];
	for (long int i = 0; i < 1000; i++)
	{
		numbers[i] = i;
		if (((numbers[i]) % 3) == 0)
		{
			sumOf += numbers[i];
		}
		else if (((numbers[i]) % 5) == 0)
		{
			sumOf += numbers[i];
		}
	//	else if ((((numbers[i]) % 3) == 0) && (((numbers[i]) % 5) == 0))
		//{
		//	sumOf -= numbers[i];
		//}

	}
	printf("the sum of the multiples of 3 and 5 below 30 is :%lld", sumOf);
	return 0;
}
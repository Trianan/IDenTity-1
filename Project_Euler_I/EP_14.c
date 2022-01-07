// Isaiah Campsall		EP_14.c			Jan. 07, 2022
/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000

int IsOdd(long long num);

int main() {
	long long bigCount = 0;
	for (int i = 2; i < MAX; i++) {
		long long chain = i;
		long long count = 0;
		while (chain != 1) {
			count++;
			if (IsOdd(chain)) {
				chain = (3 * chain) + 1;
			}
			else {
				chain /= 2;
			}
		}
		count++;
		if (count > bigCount) {
			bigCount = count;
			printf("new big count is: %lld		starting number was %d\n", bigCount, i);
		}
	}
	printf("%lld", bigCount);
	return 0;
}

int IsOdd(long long num)
{
	if (num % 2 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
//	Isaiah Campsall		Nov.12,2021		EP_10
//	Find the sum of all the primes below two million.

#include <stdio.h>
#include <stdlib.h>

constexpr; long long MAX = 2000000;

int main()
{
	long long sum = 0;
	char* comprime = (char*)malloc(MAX);
	if (comprime == NULL) {
		puts("you done fucked up");
	}
	else {
		for (int i = 0; i < MAX; i++) {
			comprime[i] = 'p';
		}
		comprime[0] = 'c';
		comprime[1] = 'c'; 
		for (int i = 0; i < MAX; i++) {
			if (comprime[i] == 'p') {
				int b = 2;
				while ((b*i) < MAX)
				{
					comprime[b * i] = 'c';
					b++;
				}
			}
		}
		for (int i = 0; i < MAX; i++) {
			if (comprime[i] == 'p') {
				sum += i;
			}
		}
		printf("%lld", sum);
		free(comprime);
	}
	return 0;
}


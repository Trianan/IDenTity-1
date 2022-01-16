// Isaiah Campsall		EP_21.cpp		Jan. 16, 2022
/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>
#include <math.h>

using namespace std;

int D(long a);


int main()
{
	int sum = 0;
	for (int a = 0; a < 10000; a++) {
		int b = D(a);
		if (a == (D(b))&& (a != b)) {
			sum += a;
			cout << a << endl;
			cout << b << endl << endl;
		}
	}
	cout << sum;
}

int D(long a)
{
	int cnt = 1;
	for (int i = 2; i <= sqrt(a); i++) {
		if (((a % i) == 0) && (a!=i)){
			if (i == sqrt(a)) {
				cnt += i;
			}
			else{
				cnt += i;
				cnt += (a / i);
			}
		}		
	}	
	if ((a == 1)||(a==0)) {
		cnt = 0;
	}
	return cnt;
}


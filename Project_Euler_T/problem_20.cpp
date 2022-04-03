/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #20: "Don't yell at me!" - Trianan - Apr 3/2022

		"n! means n * (n − 1) * ... * 3 * 2 * 1

		For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
		and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

		Find the sum of the digits in the number 100!"


	< ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;

int main() {
	int n = 100;
	string n_factorial = EulerTools::factorial(n);

	cout <<n<< "! = \n" << n_factorial 
		<< "\n\n\nThe sum of the digits of "
		<<n<<"! is: "<<EulerTools::sum_digits(n_factorial);

	return 0;
}
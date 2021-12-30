/*
	Project Euler - Problem #6: "Summing Squares N' Sheeit" - Trianan - Oct 16/2021

		"The sum of the squares of the first ten natural numbers is 385.
			The square of the sum of the first ten natural numbers is 3025.

			Hence the difference between the sum of the squares of the first 
			ten natural numbers and the square of the sum is 3025 - 385 = 2640.

			Find the difference between 
			the sum of the squares of the first one hundred natural numbers 
			and the square of the sum."

*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long int sum_squares(long int max) {
	long int sum = 0;
	for (long int i = 1; i <= max; ++i) {
		long int square = i * i;
		sum += square;
	}
	cout << "Sum of squares from 1 to " << max << " = " << sum << '\n';
	return sum;
}
long int square_sum(long int max) {
	long int square = 0;
	for (long int i = 1; i <= max; ++i) {
		square += i;
	}
	square *= square;
	cout << " Square of sum from 1 to " << max << " = " << square << '\n';
	return square;
}

int main() {
	const long int upperbound = 100;
	long int sq = square_sum(upperbound);
	long int sum = sum_squares(upperbound);
	long int result = sq - sum;
	cout << sq << '-' << sum << " = " << result << '\n';


}

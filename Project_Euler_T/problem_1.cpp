/*
	Project Euler - Problem #1: "Multiples of 3 or 5" - Trianan - Oct 3/2021

		"If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
			Find the sum of all the multiples of 3 or 5 below 1000."

*/
#include <iostream>
#include <string>

using namespace std;

int sum_multiples(int factor, int upper_bound, int lower_bound = 1) {
	// Returns the sum of all multiples of a specified factor up a specified upper bound.
	int sum = 0;
	for (int multiplier = lower_bound; multiplier <= upper_bound; ++multiplier) {
		sum += factor * multiplier;
	}
	return sum;
}

int main() {
	// Combinatorial AuB = A + B - AnB prevents double counting of multiples.
	int multiples_3 = sum_multiples(3, 333);
	int multiples_5 = sum_multiples(5, 199);
	int multiples_both = sum_multiples(15, 66);
	int answer = multiples_3 + multiples_5 - multiples_both;

	cout << "Sum of multiples of 3: " << multiples_3 << '\n'
		<< "Sum of multiples of 5: " << multiples_5 << '\n'
		<< "Some of multiples of both: " << multiples_both << '\n'
		<< "Sum of multiples of both three and five (final answer): " << answer << '\n';

}
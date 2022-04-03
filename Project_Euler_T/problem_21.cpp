/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #21: "A Sad Division of Friendship" - Trianan - Apr 3/2022

		"Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
		 If d(a) = b and d(b) = a, where a ≠ b, 
		 then a and b are an amicable pair and each of a and b are called amicable numbers.

		 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
		 The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

		 Evaluate the sum of all the amicable numbers under 10000."

	< ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;

vector<int> find_amicables(vector<int>& search_set) {
	// Returns a list of amicable pairs from a given search pool of integers.
	vector<int> amicables;
	cout << "Finding amicable-pairs in interval [" << search_set[0] << "," << search_set[search_set.size() - 1] << "] ...\n\n";

	for (int i = 0; i < search_set.size(); ++i) {
		int n = search_set[i]; //cout << n << '\n';

		bool unsearched = true;
		for (int a : amicables) // This gets rid of numbers already in set of amicables.
			if (n == a) {
				unsearched = false;
				search_set.erase(search_set.begin() + i); // Deletes element, then decrements i such that it remains at the same index for the next pass.
				--i;
			}

		if (unsearched) {
			int fsum_n = EulerTools::sum_factors(n);
			if (n != fsum_n && EulerTools::sum_factors(fsum_n) == n) {
				cout << "\t-amicable pair found: (" << n << " , " << fsum_n << ")\n";
				amicables.push_back(n);
				amicables.push_back(fsum_n);
			}
			
		} 
	}
	return amicables;
}

int main() {

	vector<int> search_set = EulerTools::generate_integer_subset(1, 10000);
	vector<int> amicable_pairs = find_amicables(search_set);

	int sum = 0;
	for (int a : amicable_pairs)
		sum += a;
	cout << "\nSum: " << sum << '\n';
	
	return 0;
}
/*					
	Project Euler - Problem #5: "Divisions are High" - Trianan - Oct 13/2021

		"2520 is the smallest number that can be divided by each 
			of the numbers from 1 to 10 without any remainder.
		What is the smallest positive number that is evenly divisible 
			by all of the numbers from 1 to 20?"

*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long long int product_factors(vector<long long int>& factors) {
	long long int product = 1;
	for (long long int factor : factors)
		product *= factor;
	return product;
}

int main() {

	long long int product = 1;
	vector<long long int> factors = { 1,2,3,5,7,11,13,17,19,20 };
	product = product_factors(factors);

	cout << "Initial product: " << product << '\n';

	for (long long int i = 1; i < 20; ++i) {
		if (product % i != 0) {
			cout << "\t-" << i << '\n';
			factors.push_back(i);
			product = product_factors(factors);
		}
	}

	cout << "  Intermediate Product: " << product << '\n';

	bool reduced = false;
	while (!reduced) {

		reduced = true;
		for (long long int factor : factors) {
			if ((product / factor) % factor == 0 && (factor != 1)) {
				product = (product / factor) / factor;
				reduced = false;
				cout << "  -> " << product << '/' << factor << " = " << (product / factor)<<'\n'
					<< "    ---> " << (product / factor) << '/' << factor << " = " <<(product/(2*factor))<< '\n';
			}
		}
	}

	cout << "   Final product: " << product << '\n';
}



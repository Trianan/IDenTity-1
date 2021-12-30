/*
	Project Euler - Problem #9: "Easy as ABC" - Trianan - Oct 30/2021

		"A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
				a^2 + b^2 = c^2
			For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
		There exists exactly one Pythagorean triplet for which a + b + c = 1000.
		Find the product abc."
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

long int sq(long int root) { // Squares input;
	return root * root;
}

void solution(long int a, long int b) { // Returns true if given values satisfy equation.
	if ((sq(a) + sq(b)) == sq(1000 - a - b))
		if (a < b && b < (1000 - a - b)) {
			cout << "Solution found! \n\t"
				<< a << "^2 + " << b << "^2 = " << (1000 - a - b) << "^2 \n\t"
				<< a << " + " << b << " + " << (1000 - a - b) << " = " << (a + b + 1000 - a - b) << "\n";
		}
}

int main() {
	for (long int a = 0; a <= 1000; ++a)
		for (long int b = 0; b <= 1000; ++b)
			solution(a, b);
}
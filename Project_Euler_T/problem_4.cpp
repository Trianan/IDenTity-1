/*
	Project Euler - Problem #4: "Palindromic Product" - Trianan - Oct 13/2021

		"A palindromic number reads the same both ways. The largest palindrome made 
			from the product of two 2-digit numbers is 9009 = 91 × 99.
			Find the largest palindrome made from the product of two 3-digit numbers."

*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool is_palindrome(long int input){
	// Determines if a given integer is a palindrome:
	ostringstream oss;
	oss << input;
	string n = oss.str();  // Converts integer to string...
	int last_index = n.size() - 1;

	if (n[0] == n[last_index]) // Rudimentary check first.
		for (int i = 0; i < n.size(); ++i) {
			if (i == (last_index - i))  // If indices are the same, search complete.
				return true;
			else if (n[i] != n[last_index - i]) // Finds mismatching digits.
				return false;
		}
	else return false; // Last digit did not match first digit.
}

int main() {
	long int largest_palindrome = 0;
	long int min = 100 * 100;
	long int max = 999 * 999;

	long int current_product = 0;
	for (long int i = 100; i <= 999; ++i)
		for (long int h = 100; h <=999; ++h){
			current_product = i * h;
			if (is_palindrome(current_product))
				if (current_product > largest_palindrome) {
					largest_palindrome = current_product;
					cout << "\t-(" << i << '*' << h << ") = " << current_product << '\n';
				}
		}
	cout << "Largest palindrome found ===>" << largest_palindrome << '\n';
}
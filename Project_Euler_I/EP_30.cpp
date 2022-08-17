// EP_30.cpp		Isaiah Campsall		June, 24, 2022
/*
		Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include "EPHeader.h"

using namespace std;

int main()
{
	int check = 0;
	int sumOfPowers = 0;
	
	vector<int> solutions;

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				for (int d = 0; d < 10; d++) {
					for (int e = 0; e < 10; e++) {
						for (int f = 0; f < 10; f++) {

							check = ((a * 100000) + (b * 10000) + (c * 1000) + (d * 100) + (e*10) + f);
							sumOfPowers = ((a * a * a * a * a) + (b * b * b * b * b) + (c * c * c * c * c) + (d * d * d * d * d) + (e * e * e * e * e) + (f*f*f*f*f));
							
							if ((check == sumOfPowers) && (sumOfPowers != 0) && (sumOfPowers != 1)) {
								solutions.insert(solutions.begin(), check);
							}

						}


					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < solutions.size(); i++) {
		cout << solutions[i] << endl;
		sum += solutions[i];
	}

	cout << "\n" << "The final sum is " << sum << "\n";
}
// Isaiah Campsall		EP_26.cpp		April 29, 2022
/*
	A unit fraction contains 1 in the numerator.
	Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
#include <iomanip>

#define DMAX 1000
#define XMAX 2001


using namespace std;

struct answer {
	int denominator;
  int series;
};


int main()
{
	bool big[DMAX];
	int* quotients = new int[DMAX*XMAX];
	if (quotients != NULL) {
		//quotients = { 0 };
		for (int i = 0; i < 1000; i++) {
			quotients[i * XMAX] = 1;
			for (int ii = 1; ii < 1001; ii++) {
				quotients[i * XMAX + ii] = 0;
			}
		}

		for (int d = 2; d < 1000; d++) {
			big[d] = false;
			//int zeros = 0;
			cout << endl << "d = " << d << endl;
			for (int i = 0; i < 2000; i++) {

				if (quotients[d * XMAX + i] / d == 0) {
					quotients[d * XMAX + i + 1] = (quotients[d * XMAX + i] * 10);
					quotients[d * XMAX + i] = 0;
					//zeros++;

				}
				else {
					quotients[d * XMAX + i + 1] = 10 * (quotients[d * XMAX + i] % d);
					quotients[d * XMAX + i] = quotients[d * XMAX + i] / d;
					//zeros = 0;
				}
				cout << quotients[d * XMAX + i];
				//if (zeros == 4) {
					//i = 74;

				//}
			}
			cout << endl;

		}
		//spaceRecord* num = new spaceRecord[10];

		answer highestRepeat{};
		highestRepeat.denominator = 0;
		highestRepeat.series = 0;

		int test1 = 0;
		int test2 = 0;
		int test3 = 0;

		int* repSize = new int[1000];
		int spaceCtr[10] = { 0 };

		for (int d = 2; d < 1000; d++) {					//d = denominator... 1/d

			//int largest = 2;								//records the largest number of spaces between two of the same number excluding numbers not in pattern
			int nSpaces[2000] = { 0 };
			int numNums = 0;								//indicates the number of unique numbers through all i's of a quotient of given d value

			for (int n = 0; n < 10; n++) {					//n = number... 0-9
				bool inPattern = false;
				for (int i = 20; i < 2000; i++) {				//i = d quotient digit index... array[d][i]

					spaceCtr[n]++;

					if (quotients[d * XMAX + i] == n) {

						nSpaces[i] = spaceCtr[n];

						if (i > 10) {

							inPattern = true;

							/*if (spaceCtr[n] >> largest) {
								largest = spaceCtr[n];
							}*/
						}

						spaceCtr[n] = 0;
					}
				}
				if (inPattern) {
					numNums++;
				}
				spaceCtr[n] = 0;
				//record and check information for current n... establish pattern?
			}
			int sum = 0;
			int largest = numNums;
			if (numNums >> 1) {
				do {
					do {
						sum = 0;
						for (int x = (largest + 3); x < ((largest * 2) + 3); x++) {
							if (x < 2000) {
								sum += nSpaces[x];													//exception being thrown X exceeds 75 (some errors in process, fix those first)!!!!!!!
							}
							else { cout << endl << "not enough available digits" << endl; }
						}
						if (sum % numNums != 0) {
							largest++;
						}

					} while (sum % numNums != 0);
					test1 = largest;
					do {
						sum = 0;
						for (int x = (largest * 2 + 4); x < ((largest * 3) + 4); x++) {
							if (x < 2000) {
								sum += nSpaces[x];													//exception being thrown X exceeds 75 (some errors in process, fix those first)!!!!!!!
							}
							else { cout << endl << "not enough available digits" << endl; }
						}
						if (sum % numNums != 0) {
							largest++;
						}

					} while (sum % numNums != 0);
					test2 = largest;
					do {
						sum = 0;
						for (int x = (largest * 3 + 4); x < ((largest * 4) + 4); x++) {
							if (x < 2000) {
								sum += nSpaces[x];													//exception being thrown X exceeds 75 (some errors in process, fix those first)!!!!!!!
							}
							else { cout << endl << "not enough available digits" << endl; }
						}
						if (sum % numNums != 0) {
							largest++;
						}

					} while (sum % numNums != 0);
					test3 = largest;
				} while ((test1 != test2) || (test1 != test3));
				repSize[d] = largest;

			}
			//record size of repetition in repSize[d]
			cout << "repetition for d = " << d << " is: " << repSize[d] << endl;
			if ((highestRepeat.series < *(repSize + d)) /*&& (d !=263)  && (d != 709) && (d != 566) && (d != 617)*/) {
				highestRepeat.series = *(repSize + d);
				highestRepeat.denominator = d;
			}
			if ((*(repSize+d) >> 20)) { big[d] = true; }
		}

		cout << endl << "Demoninator " << highestRepeat.denominator << " has the lengthiest repetition... " << endl;
		cout << "its repetition is " << highestRepeat.series << " decimal values long" << endl;
		delete[] repSize;
	}
	else {
	cout << "that did not work";
	}
	/*for (int d = 2; d < 1000; d++) {
		if (big[d] == true) {
			for (int i = 0; i < 1000; i++) {

				cout << quotients[d * XMAX + i];

			}
			cout << endl;
		}
		
	}*/
	
	delete[] quotients;
	
	return 0;
}
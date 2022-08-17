// EP_25.cpp		Isaiah Campsall		April 2, 2022
/*
	find the index of the first number in the fibbinachi sequence to have 1000 digits
*/


#include <iostream>

using namespace std;

void arrayAdd(int* arrays, int* r);


int main()
{

	int sum[1000] = { 0 };
	int* sumPtr = sum;
	int carry[2000] = { 0 };
	int* carryPtr = carry;
	carry[999] = 0;
	carry[1000 + 999] = 1;
	cout << carry[999] << endl << carry[1999] << endl;
	do {

		arrayAdd(carryPtr, sumPtr);
		for (int p = 0; p <= 999; p++) {
			cout << sum[p];
		}
		cout << endl;
		for (int ii = 0; ii < 1000; ii++) {
			carry[ii] = carry[1000 + ii];

			carry[1000 + ii] = sum[ii];
		}

	} while (sum[0] == 0);
	system("pause");
	return 0;
}

void arrayAdd(int* arrays, int* r)
{
	static long index = 1;
	index++;
	int carry = 0;
	for (int ii = 999; ii >= 0; ii--) {
		*(r + ii) = *(arrays + ii) + *(arrays + (1000 + ii)) + carry;
		if (*(r + ii) >= 10) {
			//cout << "if block entered" << endl;
			carry = 1;
			*(r + ii) = *(r + ii) % 10;
		}
		else { carry = 0; }

	}
	cout << endl << "n = " << index << ":" << endl;
}
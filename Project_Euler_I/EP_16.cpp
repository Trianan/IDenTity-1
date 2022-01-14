// Isaiah Campsall          EP_16.cpp       Jan. 13, 2022
/*
	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?
*/

#include <iostream>

using namespace std;

int main() {

	int arr[305] = { 0 };		//arr is 305 elements long because log base 2 of X is 1000. converting to a log base 10 we get logX = 1000*log2 = roughly 301.03 therefore x must have roughly 301 digits
	arr[0] = 1;
	for (int i = 0; i < 1000; i++) {
		int carry = 0;
		for (int ii = 0; ii < 305; ii++) {		//runs through the entire array
			if (arr[ii]) {					//if the element in the array is not zero
				arr[ii] *= 2;				//multiply the element by two
				arr[ii] += carry;			//add carry to the element
				if (arr[ii] >= 10) {		//if the new element is ten or higher
					carry = arr[ii] / 10;	//set carry to be the MSB of the element
					arr[ii] = arr[ii] % 10;	//set the element to be the LSB of the current element					
				}
				else {
					carry = 0;				//if the element is less than 10 there is no carry
				}
			}
			else {							//if the element is zero
				arr[ii] += carry;			//add carry to the element
				carry = 0;					//set carry to zero
			}
		}
	}
	int sum = 0;							//initiallize sum as 0
	for (int i = 0; i < 305; i++) {			
		sum += arr[i];						//add sum to the element i of arr
	}
	cout << "The sum of all digits of 2^1000 is:" << sum<<endl;	//display sum
	cout << "2^1000 = ";
	for (int i = 304; i >= 0; i--) {		//print 2^1000
		cout << arr[i];
	}
	return 0;
}
// EPHeader.h		Isaiah Campsall			June, 25, 2022

/*	June, 25, 2022:	All funtions and classes contained in this header are a work in progress...
    do not forget to check this file for potential issues or improvements regularily           */	

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>

using namespace std;

struct fraction {                                                             //so... I made a structure for dealing with fractions
																			  //it is vulnerable to changes to it's num. and denom.
	int numerator;                                                            //consider making a class out of this concept... could be pretty cool
	int denominator;														  //seriously... this thing is flawed and should be used wisely. 
	long double quotient = (long double)numerator / (long double)denominator; //initialize every instance of this struct with the numer and denom (ex.        fraction name{num, den}; )
	bool operator==(const fraction& rhs) {									  //after that... do not alter the value of the fraction unless using the *= or /= operator overload (see line 29)
		if (this->quotient == rhs.quotient)									  //otherwise, the quotient will be undefined, or simply incorrect, this is why it should be a class damnit!
			return true;
		else
			return false;
	}

	void operator*=(const fraction& rhs) {
		this->denominator *= rhs.denominator;
		this->numerator *= rhs.numerator;
		quotient = (long double)numerator / (long double)denominator;
	}
	void operator/=(const fraction& rhs) {
		this->denominator /= rhs.denominator;
		this->numerator /= rhs.numerator;
		quotient = (long double)numerator / (long double)denominator;
	}

	int digitized[2][2] = { {numerator / 10, numerator % 10}, {denominator / 10, denominator % 10} };//Numerator Or Denominator 0 for N, 1 for D
																								  //Most Significant Or Least Significant 0 for most, 1 for least
};

std::ostream& operator<<(std::ostream& out, const fraction& frac) {
	out << frac.numerator << " / " << frac.denominator;// << " = " << frac.quotient << "\n";
	return out;
}

vector<int> a_ToThe_b(int a, int b);

void BubbleSort(int a[], int arrLen);

template<typename T>
void BubbleSortXF(vector<T>& array);

void BubbleSort(vector<int>& array);

void BubbleSort(vector<double>& array);

void BubbleSortNF(vector<double>& array);

void BubbleSortNF(vector<int>& array);

void BubbleSort(vector<vector<int>>& array);

template <typename T>
vector<int> Digitize(T num);

vector<int> DecToBi(int num);

long long Factorial(int num);

template<typename T>
int GreatestCommonDenominator(T a, T b);

template<typename T>
bool IsOdd(T num);

bool IsPalindrome(vector<int> num);

int IsPrime(long num);


vector<int> a_ToThe_b(int a, int b)			//multi digit * multi digit
{
	vector<int> power = { a };
	int carry = 0;
	int cnt = 1;
	unsigned int OGSize;
	while (cnt < b) {

		OGSize = power.size();								//vector size is changed through "for" loop so original (OG) value is retained
		for (unsigned int i = 0; i < OGSize; i++) {

			while (power[0] >= 10) {
				carry = power[0] / 10;
				power.insert(power.begin(), carry);
				power[1] %= 10;
				carry = 0;
				OGSize++;
			}

			if (*(power.end() - 1 - i)) {					//if the element in the array is not zero
				*(power.end() - 1 - i) *= a;				//multiply the element by a
				*(power.end() - 1 - i) += carry;			//add carry to the element
				if (*(power.end() - 1 - i) >= 10) {			//if the new element is ten or higher
					carry = *(power.end() - 1 - i) / 10;					//set carry to be the element divided by ten, rounded down to the nearest whole number
					while (*(power.end() - 1 - i) >= 10) {
						*(power.end() - 1 - i) %= 10;	//set the element to be the LSB of the current element
					}
					if ((power.end() - 1 - i) == power.begin()) {
						power.insert(power.begin(), carry);
						carry = 0;
					}

				}
				else {
					carry = 0;				//if the element is less than 10 there is no carry
				}
			}
			else {									//if the element is zero
				*(power.end() - 1 - i) = carry;			//add carry to the element
				if (*(power.end() - 1 - i) >= 10) {
					carry = *(power.end() - 1 - i) / 10;
					*(power.end() - 1 - i) %= 10;
				}
				else { carry = 0; }							//set carry to zero
			}

			while (power[0] >= 10) {
				carry = power[0] / 10;
				power.insert(power.begin(), carry);
				power[1] %= 10;
				carry = 0;

			}
		}
		cnt++;
	}
	return power;
}

void BubbleSort(vector<int>& array)				//least to greatest
{
	char function;
	cout << "would you like to filter the vector, leaving only unique values? [y] or [n]" << endl;
	cin >> function;
	if (function == 'y') {
		function = 'f';
	}
	else { function = 'n'; }
	bool cnt = false;
	cout << endl << "Organizing From Least to Greatest" << endl;
	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				cnt = true;
				cout << ".";
			}
			if (i % 26 == 0) { cout << "\r                                                                                                    \r"; }
		}
	} while (cnt);
	cout << "\r                                                                                                     \r..........";
	if (function == 'f') {
		cout << "Eliminating Duplicates..." << endl;
		do {
			cnt = false;
			for (int i = 0; i < (array.size() - 1); i++) {

				if (array[i] == array[i + 1]) {
					array.erase(array.begin() + i);
					cout << ".";
					cnt = true;
				}

				if (i % 25 == 0) { cout << "\r                                                                                                    \r"; }
			}
		} while (cnt);
	}
	cout << "\r                                                                                                     \r..........\n";
	
}

void BubbleSortNF(vector<int>& array)				//least to greatest
{
	bool cnt = false;
	
	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				cnt = true;
				
			}
			
		}
	} while (cnt);
	

}

void BubbleSort(vector<double>& array)				//least to greatest
{
	char function;
	cout << "would you like to filter the vector, leaving only unique values? [y] or [n]" << endl;
	cin >> function;
	if (function == 'y') {
		function = 'f';
	}
	else { function = 'n'; }
	bool cnt = false;
	cout << endl << "Organizing From Least to Greatest" << endl;
	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				cnt = true;
				cout << ".";
			}
			if (i % 26 == 0) { cout << "\r                                                                                                    \r"; }
		}
	} while (cnt);
	cout << "\r                                                                                                     \r..........";
	if (function == 'f') {
		cout << "Eliminating Duplicates..." << endl;
		do {
			cnt = false;
			for (int i = 0; i < (array.size() - 1); i++) {

				if (array[i] == array[i + 1]) {
					array.erase(array.begin() + i);
					cout << ".";
					cnt = true;
				}

				if (i % 25 == 0) { cout << "\r                                                                                                    \r"; }
			}
		} while (cnt);
	}
	cout << "\r                                                                                                     \r..........\n";

}

void BubbleSortNF(vector<double>& array)				//least to greatest
{
	bool cnt = false;

	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				cnt = true;

			}

		}
	} while (cnt);


}

void BubbleSort(vector<vector<int>>& array)				//least to greatest
{
	char function; 
	cout << "would you like to filter the vector, leaving only unique values? [y] or [n]" << endl;
	cin >> function;
	if (function == 'y') {
		function = 'f';
	}
	else { function = 'n'; }
	bool cnt = false;
	cout << endl << "Organizing From Least to Greatest" << endl;
	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i].size() > array[i + 1].size()) {
				array[i].swap(array[i + 1]);
				cnt = true;
				cout << ".";
			}
			if (i % 26 == 0) { cout << "\r                                                                                                    \r"; }
		}
	} while (cnt);

	
	cout << endl << "Reorganizing ";
			if (function == 'f') { cout << "and Eliminating Duplicates..." << endl; }
		do {
			cnt = false;
			for (int i = 0; i < (array.size() - 1); i++) {

				if ((array[i] > array[i + 1]) && (array[i].size() == array[i + 1].size())) {
					cout << ".";
					array[i].swap(array[i + 1]);
					cnt = true;
				}
				if (function == 'f') {
					if (array[i] == array[i + 1]) {
						array.erase(array.begin() + i);

						cnt = true;
					}
				}
				if (i % 25 == 0) { cout << "\r                                                                                                    \r"; }
			}
		} while (cnt);
	

	cout << "\n";
}

template<typename T>
void BubbleSortXF(vector<T>& array)				//least to greatest
{
	bool cnt = false;
	do {
		cnt = false;
		for (int i = 0; i < (array.size() - 1); i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				cnt = true;
			}
		}
	} while (cnt);
		do {
			cnt = false;
			for (int i = 0; i < (array.size() - 1); i++) {

				if (array[i] == array[i + 1]) {
					array.erase(array.begin() + i);
					cnt = true;
				}

			}
		} while (cnt);
	}

void BubbleSort(int a[], int arrLen)					//does not eliminate duplicates, use a vector for filter option
{
	for (int x = 0; x < arrLen; ++x)
	{
		for (int b = 0; b < (arrLen - 1); ++b)
		{
			if (a[b] > a[b + 1])
			{
				int hold = a[b + 1];
				a[b + 1] = a[b];
				a[b] = hold;
			}
		}
	}
}	

vector<int> DecToBi(int num)
{
	vector<int> binary;
	while (num > 0) {
		binary.insert(binary.begin(), (num % 2));
		num /= 2;
	}
	return binary;
}

template<typename T>
vector<int> Digitize(T num)
{
	vector<int> digits;
	while (num != 0) {
		digits.insert(digits.begin(), (int)num % 10);
		num /= 10;
	}

	return digits;
}

long long Factorial(int num)					//this function will need to be expanded to handle very large factorials, consider using vector
{
	long long fac = 1;
	for (int i = 2; i <= num; i++) {
		fac *= i;
	}
	return fac;
}

template<typename T>
int GreatestCommonDenominator(T a, T b)
{
	if (b == 0)
		return a;
	return GreatestCommonDenominator(b, a % b);
	
}

template<typename T>
bool IsOdd(T num)				//Template Function, should be told datatype 
{
	if (num % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool IsPalindrome(vector<int> digits)
{
	if (digits.size()) {
		if (!digits[0]) { return false; }                   //if there are leading zeros, return false.
		for (int i = 0; i < digits.size() / 2; i++) {

			if (digits[i] != *(digits.end() - (i + 1))) {
				return false;
			}
		}
		return true;
	}
	else return false;
}

int IsPrime(long num)						//returns 1 if num is prime, else, returns 0
{
	if (num == (1 || 4)) { return false; }
	if ((num % 2) == 0 && (num != 2))
	{
		return 0;
	}
	for (long i = 3; i < sqrt(num) + 1; i++) {
		if(IsOdd(i)) {
			if ((num % i) == 0)
			{
				return 0;
			}
		}
	}
		return 1;
	
}

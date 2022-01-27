// Project Euler - Problem 006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Sum Square Difference"
// 
// The sum of the squares of the first ten natural numbers is,
// 
//                                                   1^2 + 2^2 + ... + 10^2 = 385
//
// The square of the sum of the first ten natural numbers is,
// 
//                                                (1 + 2 + ... + 10)^2 = 55^2 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbersand the square of the sum is
// 3025 - 385 = 2640.
// 
// Find the difference between the sum of the squares of the first one hundred natural numbersand the square of the sum.


#include <iostream>
#include <cmath>

using namespace std;

long sumofsq(int x) {

    long sum = 0;

    while (x) {
        sum += pow(x, 2);
        x--;
    }

    return sum;
}


long sqofsum(int x) {

    long sum = 0;

    while (x) {
        sum += x;
        x--;
    }

    return pow(sum, 2);
}

int main()
{
    int a = 100;
    cout << sqofsum(a) - sumofsq(a) << endl;
}
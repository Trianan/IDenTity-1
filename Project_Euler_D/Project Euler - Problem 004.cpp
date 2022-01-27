// Project Euler - Problem 004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Largest Palindrome Product"
//
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 
// = 91 × 99.
//
// Find the largest palindrome made from the product of two 3 - digit numbers.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long reverse(long x) {

    long y = 0;

    while (x >= 1) {
        y = y * 10 + (x % 10);
        x = x / 10;
    }

    return y;
}

bool palindrome(long x) {

    if (x == reverse(x))
        return true;

    else
        return false;

}

int main()
{

    long a = 999;

    vector<long> palin;

    while (a > 99) {

        long b = 999;

        while (b > 99) {

            long c = a * b;

            if (palindrome(c)) {
                palin.push_back(c);
            }

            b--;

        }

        a--;
    }

    long maxpalin = *max_element(palin.begin(), palin.end());
    cout << maxpalin << endl;
    return 0;
}
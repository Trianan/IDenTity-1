// Project Euler - Problem 005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Smallest Multiple"
//
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

#include <iostream>
using namespace std;

bool no_remainder(long x) {

    for (int i = 1; i <= 20; i++) {

        if (x % i)
            return false;
    }

    return true;
}

int main()
{
    long a = 20;

    while (!no_remainder(a)) {
        a += 20;
    }

    cout << a << endl;
}
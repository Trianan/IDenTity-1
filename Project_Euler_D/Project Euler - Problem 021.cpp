// Project Euler - Problem 021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Amicable Numbers"
//
// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 
// 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.


#include <iostream>

using namespace std;

int d(int n)
{
    int sum = 1;

    for (int i = 2; i <= (n / 2); i++)
    {
        if (!(n % i))
        {
            sum += i;
        }
    }

    return(sum);
}

void main()
{
    int sum = 0;

    int b;

    for (int a = 2; a < 10000; a++)
    {
       b = d(a);

       if ((b > a) && (d(b) == a))
       {
           sum += (a + b);
       }
    }

    cout << sum;
}
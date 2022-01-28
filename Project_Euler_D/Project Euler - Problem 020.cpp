// Project Euler - Problem 020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Factorial Digit Sum"
// 
// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10!= 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10!is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
// 
// Find the sum of the digits in the number 100!

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

std::vector<std::string> x;
string i;

string string_sum(string a, string b)
{
    if (a.size() < b.size())
        swap(a, b);

    int j = a.size() - 1;

    for (int i = b.size() - 1; i >= 0; i--, j--)
        a[j] += (b[i] - '0');

    for (int i = a.size() - 1; i > 0; i--)
    {

        if (a[i] > '9')
        {

            int d = a[i] - '0';
            a[i - 1] = a[i - 1] + d / 10;
            a[i] = (d % 10) + '0';

        }
    }

    if (a[0] > '9')
    {

        string k;
        k += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        a = k + a;

    }

    return a;

}

string string_mult(string a, int b)
{

    string sum = a;

    for (int i = 1; i < b; i++)
    {
        sum = string_sum(sum, a);
    }

    return sum;

}

void main()
{
    string factorial = "100";

    for (int i = 99; i > 1; i--)
    {
        factorial = string_mult(factorial, i);
    }

    int sum = 0;

    for (int i = 0; i < factorial.length(); i++)
    {
        sum += (factorial[i] - '0');
    }

    cout << sum;
}
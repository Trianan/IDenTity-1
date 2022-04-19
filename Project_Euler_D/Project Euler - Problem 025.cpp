// Project Euler - Problem 025.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The Fibonacci sequence is defined by the recurrence relation:
//
//		Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
// 
// Hence the first 12 terms will be :
//
//		F1 = 1
//		F2 = 1
//		F3 = 2
//		F4 = 3
//		F5 = 5
//		F6 = 8
//		F7 = 13
//		F8 = 21
//		F9 = 34
//		F10 = 55
//		F11 = 89
//		F12 = 144
// 
// The 12th term, F12, is the first term to contain three digits.
//
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits ?

#include <iostream>
#include <string>

using namespace std;

// function for adding two strings
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

int main()
{
    // assign a string for the value of the fibbonacci sequence 2 terms ago
    string n_1 = "1";

    // assign a string for the value of the fibbonacci sequence 1 term ago
    string n_2 = "1";

    // assign a string for the current value of the fibbonacci sequence
    string n_new;

    // assign a variable to keep track of which term we are on
    unsigned long term = 2;

    // use a while loop that breaks once the term has more than 1000 digits
    while (n_2.length() < 1000)
    {
        // increment the term
        term++;

        // calculate the current value
        n_new = string_sum(n_1, n_2);

        // update the past values
        n_1 = n_2;
        n_2 = n_new;
    }

    // output final term as answer
    cout << term;

    return 0;
}

// Project Euler - Problem 16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>  

using namespace std;

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

string sum_of_digits(string a)
{
    string sum = "0";

    for (int i = a.size() - 1; i >= 0; i--)
    {
        sum[sum.size()-1] += (a[i] - '0');

        for (int i = sum.size() - 1; i > 0; i--)
        {
            if (sum[i] > '9')
            {
                int d = sum[i] - '0';
                sum[i - 1] = sum[i - 1] + d / 10;
                sum[i] = (d % 10) + '0';
            }
        }

        if (sum[0] > '9')
        {
            string k;
            k += sum[0];
            sum[0] = ((sum[0] - '0') % 10) + '0';
            k[0] = ((k[0] - '0') / 10) + '0';
            sum = k + sum;
        }
    }
        
    return sum;

}

int main()
{
    string power = "2";

    for (unsigned int i = 2; i <= 1000; i++)
    {
        power = string_sum(power, power);
    }

    cout << sum_of_digits(power);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

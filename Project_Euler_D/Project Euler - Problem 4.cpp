// Project Euler - Problem 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

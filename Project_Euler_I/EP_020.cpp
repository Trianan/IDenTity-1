// Isaiah Campsall       EP_20.cpp        Jan. 15, 2022
/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <iostream>

using namespace std;

int main()
{
    long digits[156] = { 0 };
    digits[0] = 1;
    int prod = 0;
    for (int i = 2; i < 100; i++) {
        long carry = 0;
        for (int ii = 0; ii<156; ii++) {
            prod = carry + (digits[ii] * i);
            carry = prod / 10;
            digits[ii] = prod % 10;
        }
    }
    long long sum = 0;
    for (int i = 0; i < 156; i++) {
        sum += digits[i];
        cout << digits[155 - i];
    }
    cout << "\n" << sum;
}

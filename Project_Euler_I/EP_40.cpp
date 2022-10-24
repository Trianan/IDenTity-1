// EP_40.cpp        Isaiah Campsall        October 13, 2022
/*
        An irrational decimal fraction is created by concatenating the positive integers:

        0.123456789101112131415161718192021...

        It can be seen that the 12th digit of the fractional part is 1.

        If dn represents the nth digit of the fractional part, find the value of the following expression.

        d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

*/

#include "EPHeader.h"

using namespace std;

int main()
{
    vector<int> number;
    vector<int> digits;

    for (int i = 0; i < 185186; i++) {
        digits = Digitize(i);
        number.insert(number.end(), digits.begin(), digits.end());
    }
    cout << number.size() << endl << endl;
    int answer = number[1] * number[10] * number[100] * number[1000] * number[10000] * number[100000] * number[1000000];
    cout << answer;
    cout << endl << endl;
    cout << "at 1: " << number[1] << endl << endl;
    cout << "at 10: " << number[10] << endl << endl;
    cout << "at 100: " << number[100] << endl << endl;
    cout << "at 1000: " << number[1000] << endl << endl;
    cout << "at 10000: " << number[10000] << endl << endl;
    cout << "at 100000: " << number[100000] << endl << endl;
    cout << "at 1000000: " << number[1000000] << endl << endl;
}

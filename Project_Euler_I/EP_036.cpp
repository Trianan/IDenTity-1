// EP_36.cpp        Isaiah Campsall        August 15, 2022
/*
        The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

        Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

        (Please note that the palindromic number, in either base, may NOT include leading zeros.)
*/

#include "EPHeader.h"

#define MAX 1000000

int main()
{
    long long int answer = 0;
    for (int i = 0; i < MAX; i++) {
        if (IsPalindrome(Digitize(i))) {
            if (IsPalindrome(DecToBi(i))) {
                answer += i;
                std::cout << std::endl << i;
            }
        }
    }
    std::cout << std::endl << std::endl << "The sum of all double palindromic numbers below 1000000 is " << answer << std::endl;
}


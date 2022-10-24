// EP_38.cpp        Isaiah Campsall        August 17, 2022
/*
        What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of
        an integer with (1,2, ... , n) where n > 1?

        if answer = sum of ( n=[1:1:nmax] (xn)10^(9-d(total)) )
        where answer < 987654322

        if ndigits(x) = 2 >>> max number 98
        digits(99) + digits(98*2) + digits(98*3) = 2 + 3 + 3 = 8 digits < 9
        therefore x must have at least 3 digits for nmax < 4

        for ndigits(x) = 4 >>> min number is 1234
        digits(1234) + digits(1234*2) + digits(1234*3) = 4 + 4 + 4 = 12 digits > 9
        therefore if nmax = 3, ndigits(x) must = 3
        also...
        for the same conditions xmax = 987
        digits(987) + digits(987*2) + digits(987*3) = 3 + 4 + 4 = 11 digits > 9
        therefore we should establish a max for x if nmax = 3

        3x < 988, therefore x < 329.33 ......122 < x < 330 if nmax = 3

        let's see if nmax can be 2.
        2x must have 5 digits and x must have 4
        2x > 12344   AND   x < 9877

        therefore 6172 < x < 9877 if nmax = 2

        it may be possible that nmax = 5 if ndigits(x) = 1

        digits(x) + digits(x*2) + digits(x*3) + digits(x*4) + digits(x*5) = 1 + 2 + 2 + 2 + 2 = 9 digits
        just to be safe... ndigits(5 * xmax) = ndigits(5 * 99) = ndigits(45) = 2

        therefore 2x > 11    ....    x > 5.5    ....    x > 5 for nmax = 5
*/

#include "EPHeader.h"

using namespace std;




int main()
{
    /*there are three cases to check:

         1. nmax = 2     6172 < x < 9877

                                             answer = 10^5(x) + 2x

         2. nmax = 3     122 < x < 330

                                             answer = 10^6(x) + 10^3(2x) + 3x

         3  nmax = 5     5 < x < 10

                                             answer = 10^8(x) + 10^6(2x) + 10^4(3x) + 10^2(4x) + 5x
    */
    int answer = 0;
    int testAnswer = 0;
    for (int x = 6173; x < 9877; x++) {
        testAnswer = pow(10, 5) * x + 2 * x;
        if ((testAnswer > answer) && (IsPandigital(testAnswer, 1)))
            answer = testAnswer;
    }
    for (int x = 123; x < 330; x++) {
        testAnswer = pow(10, 6) * x + (pow(10, 3) * 2 * x) + (3 * x);
        if ((testAnswer > answer) && (IsPandigital(testAnswer, 1)))
            answer = testAnswer;
    }
    for (int x = 6; x < 10; x++) {
        testAnswer = pow(10, 8) * x + (pow(10, 6) * 2 * x) + (pow(10, 4) * 3 * x) + (pow(10, 2) * 4 * x) + (5 * x);
        if ((testAnswer > answer) && (IsPandigital(testAnswer, 1)))
            answer = testAnswer;
    }

    std::cout << "\n" << "the largest 1-9 pandigital number made from the parameters is " << answer << "\n";
}



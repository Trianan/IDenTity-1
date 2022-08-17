// EP_34.cpp        Isaiah Campsall        July, 18, 2022
/*
        145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

        Find the sum of all numbers which are equal to the sum of the factorial of their digits.

        Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include "EPHeader.h"

using namespace std;

int FactorialSum(int n);

int main()                                                      //I'll admit it... I cheated... looked up some assistance online but did not copy any code... it turned out similar though
{                                                               //basically i had all sorts of ideas but neglected to establish a maximum. what i found online showed the logic as follows:
    int sum = 0;                                                //n = the number... d = number of digits in n... 10^(d-1) <= n < 10^(d)
    for (int i = 10; i < 1814403; i++) {                        //for example... 1000 <= 2598 < 10000        or      10^(3) <= 2598 < 10^(4)
        if (FactorialSum(i) == i) {                             //the largest number containing any number of digits is always made of all nines.... 999 is the largest 3 digit number
            cout << i << endl;                                  //assuming n is the largest possible value for a d value and keeping in mind that n = the sum of the factorials of its digits
            sum += i;                                           //....    10^(d-1) <= d*9! < 10^(d)
        }                                                       //taking the log of each statement.... (d-1) <= log(d) + log(9!) < (d)
    }                                                           //log(9!) ≈ 5.5598 .... d-1 <= log(d) + 5.5598 < d
    cout << endl << "the answer is: " << sum;                   // add 1 to each statement.... d <= log(d) + 6.5598 < d+1 .... subtract log(d) from each statement ....
}                                                               // d - log(d) <= 6.5598 < d+1   .... lets test some d values... if d = 4
                                                                // 4 - log(4) = 3.3979 < 6.5598 so that's good but 4 + 1 = 5 which is NOT greater than 6.5598
int FactorialSum(int n)                                         //therefore the maximum number of digits is not 4... experiment yourself for a bit but the only whole number that works here
{                                                               // is d = 7 
    int sum = 0;                                                // so the current max is 9999999 however 9999999 != 7*9! ... 7*9! = 2540160
    while (n > 0) {                                             // the new max is 2540160 so lets try (2! + 6*9!) = 2177282
        sum += Factorial(n % 10);                               // and again (2! + 1! + 5*9!) = 1814403
        n /= 10;                                                // we could keep doing this to establish a lower and lower maximum buuuuut i got bored and this works well enough
    }
    return sum;
}

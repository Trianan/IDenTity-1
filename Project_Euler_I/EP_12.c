// EP_12        Isaiah Campsall         Dec. 20, 2021
//What is the value of the first triangle number to have over five hundred divisors

#include <stdio.h>
#include <math.h>

int main()
{
    long long nDiv = 0;
    long long num = 1;
    long long adder = 2;

    while (nDiv < 500) {
        nDiv = 0;
        
        for (int i = 1; i <= sqrt(num); i++) {

            if ((num % i) == 0) {
                nDiv+=2;
            }
            if (i == sqrt(num))
            {
                nDiv -= 1;
            }


        }
        if (nDiv < 500) {
            num += adder;
            adder++;
        }
    }
    printf("%lld", num);
    return 0;
}
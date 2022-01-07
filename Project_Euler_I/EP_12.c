// EP_12        Isaiah Campsall         Dec. 20, 2021
//What is the value of the first triangle number to have over five hundred divisors

#include <stdio.h>
#include <math.h>

int main()
{
    long long nDiv = 0;
    long long num = 1;         //initiallized as the first triangle number
    long long adder = 2;       //initialized as the first number to be added to num to create the triangle sequence

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
        if (nDiv < 500) {       //if there are less than 500 divisors...
            num += adder;       //set num to num plus adder
            adder++;            //incriment adder
        }
    }
    printf("%lld", num);
    return 0;
}

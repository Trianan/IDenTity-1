// EP_23.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. 
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. 
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <math.h>

#define NMAX 28124

using namespace std;

int SumDivs(int num);

int main()
{
    char* status = (char*)malloc(NMAX*sizeof(char));
    char* status2 = (char*)malloc(NMAX * sizeof(char));
    int sumDivi = 0;
    for (int i = 0; i < NMAX; i++) {
        sumDivi = SumDivs(i);

        if (sumDivi == i) {
            status[i] = 'p';
        }
        else if (sumDivi < i) {
            status[i] = 'd';
        }
        else {
            status[i] = 'a';
        }
        status2[i] = 'n';
    }
   
    for (int i = 0; i < NMAX; i++) {
        if (status[i] == 'a') {
            if ((i * 2) < NMAX) {
                status2[2 * i] = 'y';
            }
            for (int ii = (i+1); (i + ii) < NMAX; ii++) {
                if (status[ii] == 'a') {
                    status2[i + ii] = 'y';
                }
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < NMAX; i++) {
        if (status2[i] == 'n') {
            sum += i;
        }
    }
    cout << sum;
    free(status);
    free(status2);
}


int SumDivs(int num)
{
    int sum = 0; 
    for (int i = 1; i <= sqrt(num); i++) {
        if ((num % i) == 0) {
            if (i == sqrt(num)) {
                sum += i;
            }
            else {
                sum += i;
                if (num / i != num) {
                    sum += (num / i);
                }
            }
        }
    }
    return sum;
}
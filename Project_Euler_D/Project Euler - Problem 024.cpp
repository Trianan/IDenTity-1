// Project Euler - Problem 024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If 
// all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 
// 1 and 2 are:
//
//                                                  012   021   102   120   201   210
//
// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9 ?

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// function to calculate the factorial of a given number
unsigned long factorial(int n)
{
    if (n < 0)
    {
        throw invalid_argument("factorial argument must be positive");
    }
    
    else if (n == 0)
    {
        return 1;
    }

    else
    {
        unsigned long factorial = 1;

        for (int i = 1; i <= n; i++)
        {
            factorial = factorial * i;
        }

        return factorial;
    }
}

int main()
{
    // initialize variable for solution
    unsigned long solution = 0;

    // initialize variable to see how far into the lexicographic list of permutations we still need to go
    unsigned long counter = 1000000;

    // create a vector as a list of digits that have not been used 
    vector<int> digits_left = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // create a variable to determine which digit will be picked each round
    int n;

    for (int i = 9; i >= 0; i--)
    {
        // if the counter is higher than 0, we still have to go farther into the list
        if (counter > 0)
        {
            // if the counter does not evenly divide by our current factorial, we can divide to find n
            if (counter % factorial(i))
            {
                n = counter / factorial(i);
            }

            // if the counter does evenly divide by our current factorial, we have reached the exact number
            // this means the current n needs to be decremented by one, and then afterwards we will just take the largest n possible
            else
            {
                n = (counter / factorial(i)) - 1;
            }

            // now we reset the counter as the remainder after dividing the factorial value
            counter = counter % factorial(i);
        }

        // if the counter is at 0, we have arrived at the number
        else
        {
            // just keep using the highest digit possible
            n = digits_left.size() - 1;
        }

        // multiply the chosen digit by the power of 10 we are on
        solution += digits_left[n] * pow(10, i);

        // erase the digit that was used
        digits_left.erase(digits_left.begin() + n);
    }

    // output the solution
    cout << solution;

    return 0;
}


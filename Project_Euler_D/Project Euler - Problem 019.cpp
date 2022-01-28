// Project Euler - Problem 019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// "Counting Sundays"
// 
// You are given the following information, but you may prefer to do some research for yourself.
//
// - 1 Jan 1900 was a Monday.
// - Thirty days has September,
//   April, Juneand November.
//   All the rest have thirty - one,
//   Saving February alone,
//   Which has twenty - eight, rain or shine.
//   And on leap years, twenty - nine.
// - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// 
//   How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <iostream>

using namespace std;

int main()
{
    int y = 1900;

    int m = 1;

    int d_of_w = 1;

    int sum = 0;



    while (y <= 2000)
    {

        while (m <= 12)
        {

            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
                d_of_w += 3;

            else if (m == 2)
            {

                if (!(y % 4) && ((y % 100) || !(y % 400)))
                    d_of_w += 1;

            }

            else
                d_of_w += 2;

            if ((d_of_w == 7) && (y != 1900))
                sum += 1;

            else if (d_of_w == 8)
                d_of_w = 1;

            else if (d_of_w == 9)
                d_of_w = 2;

            else if (d_of_w == 10)
                d_of_w = 3;

            m++;

        }

        y++;

        m = 1;
    }

    cout << sum;

}
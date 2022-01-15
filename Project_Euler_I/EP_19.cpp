// Isaiah Campsall      EP_19.cpp       Jan. 14, 2022 
/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>

using namespace std;

struct mo{

    int days;
    int position;

}jan, feb, mar, apr, may, jun, jul, aug, sep, otr, nov, dcm;

int main()
{
    jan.days = 31;   
    feb.days = 28;  
    mar.days = 31; 
    apr.days = 30; 
    may.days = 31;
    jun.days = 30;   
    jul.days = 31;  
    aug.days = 31;   
    sep.days = 30;
    otr.days = 31;  
    nov.days = 30;    
    dcm.days = 31;    

    int total = 0;
    int dayInd = 1;
    for (int i = 1900; i < 2001; i++) {             //i represents the year
       
        if (((i % 4 == 0) && (i % 100 != 0)) || ((i % 100 == 0) && (i % 400 == 0))) {     //if it is a leap year, set feb days to 29, if not, set feb days to 28
            feb.days = 29;
        }
        else {
            feb.days = 28;
        }

        for (int ii = 0; ii < 12; ii++) {           //ii represents month
            mo x;
            switch (ii) {
            case 0: {
                x = jan;
                break;
            }
            case 1: {
                x = feb;
                break;
            }
            case 2: {
                x = mar;
                break;
            }
            case 3: {
                x = apr;
                break;
            }
            case 4: {
                x = may;
                break;
            }
            case 5: {
                x = jun;
                break;
            }
            case 6: {
                x = jul;
                break;
            }
            case 7: {
                x = aug;
                break;
            }
            case 8: {
                x = sep;
                break;
            }
            case 9: {
                x = otr;
                break;
            }
            case 10: {
                x = nov;
                break;
            }
            case 11: {
                x = dcm;
                break;
            }

            }                   //determines month x

            for (int iii = 0; iii < x.days; iii++) {         //iii represents days and cannot exceed the allotted days for a given month
                
                if (dayInd % 7 == 0) {
                    dayInd = 0;
                }
                if ((!dayInd) && (!iii) && (i != 1900)) {
                    total++;
                }
                dayInd++;
            }
        }        
    }
    cout << total;
}
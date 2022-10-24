// EP_043.cpp        Isaiah Campsall        October 24, 2022
/*
        The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, 
        but it also has a rather interesting sub-string divisibility property.

        Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

        - d2d3d4 = 406 is divisible by 2
        - d3d4d5 = 063 is divisible by 3
        - d4d5d6 = 635 is divisible by 5
        - d5d6d7 = 357 is divisible by 7
        - d6d7d8 = 572 is divisible by 11
        - d7d8d9 = 728 is divisible by 13
        - d8d9d10 = 289 is divisible by 17
        
        Find the sum of all 0 to 9 pandigital numbers with this property.
*/

#include "EPHeader.h"

using namespace std;

ostream& operator<<(std::ostream& out, vector<int>& pans);

bool FitsBill(int test[]);

int main()
{

    int test[7] = { 0 };

    long long answer = 0;
    vector<int>set = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    do{
         test[0] = (set[1] * 100) + (set[2] * 10) + (set[3]);
         test[1] = (set[2] * 100) + (set[3] * 10) + (set[4]);
         test[2] = (set[3] * 100) + (set[4] * 10) + (set[5]);
         test[3] = (set[4] * 100) + (set[5] * 10) + (set[6]);
         test[4] = (set[5] * 100) + (set[6] * 10) + (set[7]);
         test[5] = (set[6] * 100) + (set[7] * 10) + (set[8]);
         test[6] = (set[7] * 100) + (set[8] * 10) + (set[9]);
        if (FitsBill(test)) {
                answer += Numerize(set);
        }     
    } while (next_permutation(set.begin(), set.end()));

    cout << answer;;
}

ostream& operator<<(std::ostream& out, vector<int>& pans) {
    for (int i = 0; i < pans.size(); i++) {
        out << pans[i];
    }
    out << std::endl;
    return out;
}

bool FitsBill(int test[])
{
        if (test[0] % 2 == 0) {
            if (test[1] % 3 == 0) {
                if (test[2] % 5 == 0) {
                    if (test[3] % 7 == 0) {
                        if (test[4] % 11 == 0){
                            if (test[5] % 13 == 0){
                                if (test[6] % 17 == 0) {
                                return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    return false;
}


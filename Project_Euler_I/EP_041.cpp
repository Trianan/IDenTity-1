// EP_41.cpp        Isaiah Campsall        October 20, 2022
/*
        We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

        What is the largest n-digit pandigital prime that exists?
*/

#include "EPHeader.h"

using namespace std;

int PermuteDown(int num);

int main()
{
    static int tally = 0;
    int answer = 0;
    for (int i = 987654321; i > 10; i = PermuteDown(i)) {
        tally++;
        switch (tally) {
        case 362881:
            i -= 900000000;
            break;
        case 403202:
            i -= 80000000;
            break;
        case 408243:
            i -= 7000000;
            break;
        }

            if (IsPrime(i)) {
                answer = i;
                break;
            }
    }

        std::cout << endl << answer;
}


int PermuteDown(int num){
    int pNum = 0;
    vector<int> number = Digitize(num);
    prev_permutation(number.begin(), number.end());
    for (int i = 0; i < number.size(); i++) {
        pNum += number[i] * (pow(10, (number.size()-(i+1))));
    }
    return pNum;
}

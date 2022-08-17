// EP_35.cpp        Isaiah Campsall        August 13, 2022
/*
        The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

        There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

        How many circular primes are there below one million?
*/

#include "EPHeader.h"

bool CircleCheck(vector<int>& digitized, vector<int>& primes);

bool CircleCheck(vector<int>& digitized, vector<int>& primes){
    std::rotate(digitized.begin(), digitized.begin() + 1, digitized.end());
    int prime = 0;
    for (int i = 0; i < digitized.size(); i++){
        prime += digitized[i] * pow(10, digitized.size()- (1 + i));
    }
    return IsPrime(prime);
}


int main()
{
    int answer = 13;
    vector<int> primes;
    for (int i = 100; i < 1000000; i++) {
        if (IsPrime(i))
            primes.push_back(i);

    }
    primes.push_back(0);
    vector<vector<int>> digitized(primes.size());               //creates a vector of vectors of ints for storing each prime number as a digitized version
    int hold = 0;
    for (int i = 0; i < primes.size(); i++) {                   //loop that goes through each prime number in the "primes" vector
        hold = primes[i];
        while (hold != 0) {                                         //this while loop breaks each prime into individual digits and stores them in the "digitized" vector
            digitized[i].insert(digitized[i].begin(), hold % 10);
            hold /= 10;
        }
        for (int ii = 0; ii < digitized[i].size(); ii++) {
            if (!CircleCheck(digitized[i], primes)) {
                break;
            }
            if (ii + 1 == digitized[i].size()) {
                answer++;
                std::cout << primes[i] << std::endl;
            }
        }
    }
    std::cout << std::endl << "there are " << answer << " circular primes below 1,000,000!" << std::endl;
}

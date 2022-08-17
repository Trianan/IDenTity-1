// EP_37.cpp        Isaiah Campsall        August 16, 2022
/*
    The number 3797 has an interesting property. 
    Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 
    3797, 797, 97, and 7. 
    Similarly we can work from right to left: 
    3797, 379, 37, and 3.

    Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

    NOTE: 2, 3, 5, and 7 are NOT considered to be truncatable primes.
*/

#include "EPHeader.h"

bool IsDoubleTrunc(long long int num);

int main()
{

    int cnt = 0;
    long long int sumAnswer = 0;
    vector<long long int> primes;
    for (long long i = 0; i < 1000000; i++) {
        if (IsPrime(i)) primes.push_back(i);
    }

    for (int i = 2; cnt < 11; i++) {
        if (IsDoubleTrunc(primes[primes.size()-i])) {
            sumAnswer += primes[primes.size() - i];
            cnt++;
            std::cout << primes[primes.size() - i] << std::endl;
        }
    }
    std::cout << std::endl << "the sum of all eleven truncatable primes is " << sumAnswer << std::endl;
}

bool IsDoubleTrunc(long long int num)
{
    for (int div = 10; div < num; div *= 10) {

        if (!IsPrime(num % div) || !IsPrime(num / div)) {
            return false;
        }
    }
    return true;
}



// EP_31.cpp        Isaiah Campsall        July, 01, 2022
/*
        How many different ways can £2 be made using any number of coins?
*/

#include "EPHeader.h"

using namespace std;

int main()
{
    int tally = 0;
    for (int h = 0; h < 2; h++)
        for (int g = 0; g < 3; g++)
            for (int f = 0; f < 5; f++)
                for (int e = 0; e < 11; e++)
                    for (int d = 0; d < 21; d++)
                        for (int c = 0; c < 41; c++)
                            for (int b = 0; b < 101; b++)
                                for (int a = 0; a < 201; a++)
                                    if ((a * 1) + (b * 2) + (c * 5) + (d * 10) + (e * 20) + (f * 50) + (g * 100) + (h * 200) == 200) {tally++; }
    cout << tally;

}

// EP_39.cpp        Isaiah Campsall        October, 10, 2022
/*
        If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

        {20,48,52}, {24,45,51}, {30,40,50}

        For which value of p ≤ 1000, is the number of solutions maximised?


        we should establish a function for nsolutions(p) 
        we know that p must be a whole number just as a, b, and c must also be whole numbers
        it is also known that for right angle triangles, we can use trigonometric idenities
        c^2 = a^2 + b^2      >>>      a and b are whole numbers so b^2 and a^2 must be perfect squares
        also, the sum of those perfect squares must also be a perfect square.

        choose a value of 'a' then square it.  

*/

#include "EPHeader.h"

using namespace std;

int main()
{
    vector<int> perimeters(1001);

    for (int i = 0; i < 1001; i++) {
        perimeters[i] = 0;
    }
    unsigned int b = 1000000;
    double test;
    for (unsigned int p = 1; p < 1001; p++) {
        for (unsigned int c = 1+ (p / (sqrt(2)+1)); c <= (p / 2); c++) {
            for (unsigned int a = 1; a <= b; a++) {
                b = p - (a + c);
                test = sqrt(((double)c * (double)c) - ((double)a * (double)a));
                if (b == test) {
                    cout << "{" << a << "," << b << "," << c << "}" << "for p = " << p << endl;
                    perimeters[p]++;
                }
            }
            b = 1000;
        }

        //check here if this p value has the most solutions
    }
    int largestP = 0;
    int largestVal = 0;
    for (int i = 0; i < 1001; i++) {
        if (perimeters[i] > largestVal) {
            largestP = i;
            largestVal = perimeters[i];
        }
    }
    cout << "the largest possible set of answers exists in perimeter value p = " << largestP;
}

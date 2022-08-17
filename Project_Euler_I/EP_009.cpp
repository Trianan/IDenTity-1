//  Isaiah Campsall      Nov. 12, 2021       EP_9
//  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//  Find the product abc.

#include <stdio.h>
#include <math.h>

int main()
{
    for (double a = 1; a < 998; a++)
    {
        for (double b = 1; b < 998; b++)
        {
            double c = sqrt((a * a) + (b * b));
            if (a + b + c == 1000)
            {
                printf("%.1f, %.1f, %.1f", a, b, c);
                return 0;
            }
        }
    }
}

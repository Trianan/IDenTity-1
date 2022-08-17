// EP_33.cpp        Isaiah Campsall        July 14, 2022
/*
        49/98 = 4/8 ... it may look as though the nines cancel out when, in fact, they do not
        there are four of these types of fractions in the form n/d where n<d & 9<n<99 & 10<d<100
        find the denominator of the simplified fractional form of the product of these fractions

        (10/50 = 1/5 is a trivial example. trivial examples are not to be included
*/

#include "EPHeader.h"

using namespace std;





int main()
{  
    
    
    vector<fraction> sampleFractions;                           //see EPHeader.h for information on the "fraction" struct
    vector<fraction> testFractions;
   
    for (int num = 10; num < 100; num++) {                      //make every sample fraction and store in sampleFractions vector
        for (int den = 99; den > num; den--) {
            fraction load{ num, den };
            sampleFractions.push_back(load);
        }
    }

    for (int num = 1; num < 10; num++) {                        //make every possible fraction that meets the num < den requirement but uses only single digit numbers
        for (int den = 9; den > num; den--) {                   //we're always going to compare the "strange" fractions to fractions using single digit integer values 
            fraction load{ num, den };                          //as stated in EPHeader.h instances of the "fraction" struct must always be initialized with the values set.
            testFractions.push_back(load);                      //otherwise the quotient value will be undefined
        }
    }

    vector<double> quotientList;

    for (int i = 0; i < testFractions.size(); i++) {            //for every instance where a test quotient is the same as a sample quotient store that quotient
        for (int ii = 0; ii < sampleFractions.size(); ii++) {
            if (testFractions[i] == sampleFractions[ii]) {
                quotientList.push_back(testFractions[i].quotient);
            }
        }
    }
    
    BubbleSortXF(quotientList);                                   //sort and filter all the quotients

    vector<fraction> emptyFVec;                                     //create an empty fraction vector to pushback into finalFractions as needed

    vector<vector<fraction>> finalFractions;                    //make a vector of vectors of fractions to store all the remaining fractions in, sorted by quotient value

    for (int i = 0; i < quotientList.size(); i++) {
        for (int ii = 0; ii < testFractions.size(); ii++) {
            if (quotientList[i] == testFractions[ii].quotient) {

                finalFractions.push_back(emptyFVec);
                finalFractions[i].push_back(testFractions[ii]);
            }
        }
        for (int ii = 0; ii <sampleFractions.size(); ii++) {
            if (quotientList[i] == sampleFractions[ii].quotient) {
             
                finalFractions.push_back(emptyFVec);
                finalFractions[i].push_back(sampleFractions[ii]);
            }
        }
    }

    for (int i = 0; i < finalFractions.size(); i++) {
        if (finalFractions[i].size() != 0) {

            for (int ii = 0; ii < finalFractions[i].size(); ii++) {

            }
        }
    }
    vector<fraction> answers;                                                     //at this point, final fractions is organized into vectors of fractions whose quotients are equal
    for (int i = 0; i < finalFractions.size(); i++) {                       // check for strange fraction
        if (finalFractions[i].size() != 0) {
            for (int ii = 0; ii < finalFractions[i].size(); ii++) {
                fraction* fFp = &finalFractions[i][ii];             //for the sake of all things holy I made a pointer to the specific fraction with a SHORTER NAME!
                if (fFp->digitized[1][1] != 0 && fFp->digitized[1][0] != 0) {               // hence eliminating trivial examples... there's an easier way for sure.... meh.
                    for (int dig = 0; dig < 2; dig++) {
                        if((fFp->digitized[0][dig] == fFp->digitized[1][0]) && (((double)fFp->digitized[0][(dig + 1) % 2] / (double)fFp->digitized[1][1]) == fFp->quotient)) {
                            cout << "\n~~~~~~\n" << * fFp << " = " << fFp->digitized[0][(dig + 1) % 2] << "/" << fFp->digitized[1][1] << "\n";
                            answers.push_back(*fFp);
                        }
                                                                              
                        if ((fFp->digitized[0][dig] == fFp->digitized[1][1]) && (((double)fFp->digitized[0][(dig + 1) % 2] / (double)fFp->digitized[1][0]) == fFp->quotient)) {
                            cout << "\n~~~~~~\n" << *fFp << " = " << fFp->digitized[0][(dig + 1) % 2] << "/" << fFp->digitized[1][0] << "\n";
                            answers.push_back(*fFp);
                        }

                    }
                    
                }
            }
        }
    }
                                     /*
                                                       I feel the need to explain myself... it's very confusing code, Lines 81-102, I mean. 
                                                       If you got it, you can move on though. basically, its going through all the final fractions
                                                       It is looking for a couple things:

                                                                    1. Are either of the denominator's digits equal to any of the numerators digits?

                                                                    2. if yes to "1.", after removing the equal digits, do the remaining digits compose
                                                                    a fraction whoes value is equal to the quotiant of the original fraction?

                                                                    If yes to "2.", we've got a strange fraction... put it in the "answers" vector
                                                      
                                                       Okay... back to the program
                                                                                 
                                     */

    cout << "\n\n\n";
    fraction ProductFraction = { 1, 1 };            // create a fraction to multiply the answers into
    for (int i = 0; i < answers.size(); i++) {
        ProductFraction *= answers[i];              // multiply all the answer fractions
    }
    cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nthe final fraction is " << ProductFraction << endl;

    fraction gCD{ GreatestCommonDenominator(ProductFraction.denominator, ProductFraction.numerator), GreatestCommonDenominator(ProductFraction.denominator, ProductFraction.numerator) };
     

    ProductFraction /= gCD;

    cout << "\nas a simplified fraction that is " << ProductFraction << "\n\nThe denominator's value is therefore " << ProductFraction.denominator << "\n\n";
  
}

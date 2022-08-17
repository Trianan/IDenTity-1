// EP_32.cpp        Isaiah Campsall        July, 10, 2022
/*
        15234, is 1 through 5 pandigital.
        Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
*/

#include "EPHeader.h"

using namespace std;

int main()
{
    vector<int> set = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };        //contains the set of numbers that need to be used

    vector<int> holdNums;
    vector<int> holdSet = set;                              //set and numbers are going to be truly dicked around with so the data is held in the hold values
    vector<int> prodHold;

    vector<int> answers;                                    //hold all valid products in a dynamic array so they can be filtered for duplicates and summed

    vector<int> numbers = {1, 2, 3, 4, 5};                  //9 choose 5, so we start with 1, 2, 3, 4, 5 this will change after each iteration of the loop on line 40

    int testing[5];                                         //stores each permutation of the set of 5 to be tested for a * b = c pandigital

    int a_1 = 0;                                            //the numbers represent number of digits.
    int b_4 = 0000;                                         //ex. if numbers = {1, 2, 3, 4, 5}, then (a_1 = 1, b_4 = 2345), and (a_2 = 12, b_3 = 345) 
                                                            //this way, from one permutation of the chosen set, we can test both a_1 * b_4 and a_2 * b_3 
    int a_2 = 00;
    int b_3 = 000;

    int product = 0;
    
    int sum = 0;
    int counter;
    int reps;
    int fac = Factorial((int)numbers.size());

    bool pandigital = false;

    for (int i = 0; i < 126; i++) {         //choose 5 from 9
       
        if (numbers[4] == 10) {                             //looks more complicated than it is... start with 1, 2, 3, 4, 5
                numbers[3]++;                               //then 1, 2, 3, 4, 6
                                                            //then 1, 2, 3, 4, 7
            if (numbers[3] == 9) {                          //carry on until the last number reaches its max, 9. (see line 42)
                numbers[2]++;                               //when the max is reached, increment the (n-1)nth number and set the nth digit one higher... 1, 2, 3, 5, 6
                                                            //this pattern repeats through the other numbers
                if (numbers[2] == 8) {                      //this line, if the third number has exceeded its max (7), increment the second number and
                    numbers[1]++;                           //set the third = the second +1, the fourth = the third +1, and the fifth = the fourth +1 
                                                            //1, 2, 7, 8, 10  --> 1, 2, 7, 9, 10 --> 1, 2, 8, 9, 10 --> 1, 3, 4, 5, 6
                    if (numbers[1] == 7) {                  
                        numbers[0]++;

                        numbers[1] = numbers[0] + 1;
                    }
                    numbers[2] = numbers[1] + 1;
                }
                numbers[3] = numbers[2] + 1;
            }
            numbers[4] = numbers[3] + 1;
        }
        holdNums = numbers;

        
        for (int n = 0; n < numbers.size(); n++) {          //after this loop, only unused numbers remain in the "set" vector
            
            for (int v = 0; v < set.size(); v++) {
                if (numbers[n] == set[v]) {
                    set.erase(set.begin() + v);  //erase the value from "set" vector
                    break;
                }
            }
            
        }
        
        
        for (int ii = 0; ii < 120; ii++) {             //permute the chosen five
            numbers = holdNums;
            counter = ii;
            fac = 120;
            for (int n = 0; n < 5; n++) {
                if (counter == 0) {
                    testing[n] = numbers[0];
                    
                    numbers.erase(numbers.begin());
                }
                else if(ii!=121) {
                    fac /= (5 - n);
                    
                  
                    reps = counter / fac;
                    counter -= (reps * fac);
                    testing[n] = numbers[reps % numbers.size()];
                    
                    numbers.erase(numbers.begin() + (reps % numbers.size()));
                }
                
            }   
           
            a_1 = testing[0];
            b_4 = 1000 * testing[1] + 100 * testing[2] + 10 * testing[3] + testing[4];
            product = a_1 * b_4;

            

            while (product > 0){
                prodHold.push_back(product % 10);
                product /= 10;
            }
            BubbleSortNF(prodHold);           //sort digits in prodHold least to greatest (set is organized the same so it makes checking... erm... pandigitalness easier)
            product = a_1 * b_4;
            if (prodHold.size() == set.size()) {
                for (int panCheck = 0; panCheck < set.size(); panCheck++) {
                    if (set[panCheck] != prodHold[panCheck]) { 
                        pandigital = false;
                        panCheck = set.size();
                    }
                    else {
                        pandigital = true;
                    }

                }
                if (pandigital) {
                    
                    cout << a_1 << " * " << b_4 << " = " << product << endl;
                    answers.push_back(product);
                }
            }
            prodHold.clear();

            a_2 = 10 * a_1 + testing[1];
            b_3 = 100 * testing[2] + 10 * testing[3] + testing[4];
            product = a_2 * b_3;

            
            while (product > 0) {
                prodHold.push_back(product % 10);
                product /= 10;
            }
            BubbleSortNF(prodHold);           //sort digits in prodHold least to greatest (set is organized the same so it makes checking... erm... pandigitalness easier)
            product = a_2 * b_3;
            if (prodHold.size() == set.size()) {
                for (int panCheck = 0; panCheck < set.size(); panCheck++) {
                    if (set[panCheck] != prodHold[panCheck]) {
                        pandigital = false;
                        panCheck = set.size();
                    }
                    else {
                        pandigital = true;
                    }

                }
                if (pandigital) {
                    
                    cout << a_2 << " * " << b_3 << " = " << product << endl;
                    answers.push_back(product);
                }
            }
            prodHold.clear();
        }

        numbers = holdNums;
        numbers[4]++;
        
        set = holdSet;
    }

    for (int i = 0; i < answers.size(); i++) {
        sum += answers[i];
        for (int ii = i+1; ii < answers.size(); ii++) {
            if (answers[i] == answers[ii]) {
                answers.erase(answers.begin() + ii);
               
            }
        }        
    }
    cout  << endl << "the sum of all products whose a * b = c identity is 1-9 pandigital (not including repeated products) is: " << sum;
}
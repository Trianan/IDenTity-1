// Isaiah Campsall      EP_24.cpp        Jan. 17, 2022
/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <iostream>
#include <vector>
#include <Windows.h>
#include "EPHeader.h"


using namespace std;

long long Factorial(int num);
using namespace std;

int main()
{
    vector<int> container;// = { 0,1,2,3,4,5,6,7,8,9 };
    int n = 0;                              //tracks number of values available to permute   
    int counter;                            //holds the index of lexicographical permutation being sought after
    int ctrl;
    cout << "enter the numbers you wish to permute one at a time, each followed by the enter key" << endl << "Type 999 to finish" << endl;

    do {
        cin >> ctrl;                              //accept user input
        if (ctrl != 999){
            container.push_back(ctrl);            //add input to "container"
        n++;                                      //increment "n"
        }
    } while (ctrl != 999);                        //999 is sentinel value
    BubbleSort(container);                      //sorts "container" from least to greatest
    int* answer = new int[n];               //eventually holds final answer
    cout << endl << "where 0123 is the first lexicographical permutation (n = 1) of 0, 1, 2, and 3" << endl << "what nth permutation would you like to know ? " << endl;
    cin >> counter;                         //assign user input to "counter" (the index the program searches for)
    counter -= 1;                           //compensates for my method using an index starting at 0 but question asks for index starting at 1

    int facN = Factorial(n);                //calculates the factorial of "n" and assigns to "facN"
    
    int repetitions = 0;                    //contains number of (n-i)! that fit into counter
    
    for (int i = 0; i < n; i++) {           //each loop sets one value of "answer" until n loops
        if (counter == 0) {                         //if the counter has reached zero, each value in "container" is in the right place, simply fill "answer" with "container" in order
            answer[i] = container[0];
        }

        facN /= (n - i);                            // n! --> (n-1)!
        repetitions = counter / facN;               //how many times does answer[i] incriment?
        counter -= (repetitions * facN);            //remove repetition * factorial from counter

        answer[i] = container[repetitions % container.size()];      //set answer[i] to the value in container at index [repetitions] (max value is limied by modulus
        container.erase(container.begin() + (repetitions % container.size()));  //erase the value from container

        cout << answer[i];                                              //output answer[i]
        Sleep(350);      //pause for effect
    }
    delete[] answer;
}


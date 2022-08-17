// EP_22.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#define XMAX 15
#define YMAX 5163

using namespace std;

int AlphNum(char alpha);
int SortByAlpha(char* letters);

int main()
{
    char test;
    char* firstN = (char*)malloc(YMAX*XMAX*sizeof(char));
    ifstream names;
    names.open("names.txt");
    int i = 0;
    int ii = 0;
    while (!names.eof()) {
        names >> test;
        
        if (test == ('\"')) {
            do {
                names >> firstN[i*XMAX + ii];
                ii++;
            } while (firstN[i*XMAX + ii-1] != '\"');
           /* for (int ii = 0; firstN[i][ii-1] != '\"'; ii++) {

                names >> firstN[i][ii];
                
            }*/
            firstN[i*XMAX + ii - 1] = '\0';
            ii = 0;
            i++;
        }            
    }
    int go = 1;
    while (go) {
        go = SortByAlpha(firstN);
   }
    //put an alphabetical sorting function here... Sorry future Isaiah...
    

    long long unsigned final = 0;
    long long sum = 0;
    long long* worth = (long long*)malloc(YMAX*sizeof(long long));
    for (long long i = 0; i < YMAX; i++) {
        worth[i] = 0;
    }
    for (long long i = 0; i < YMAX; i++) {
        for (int ii = 0; ii < XMAX; ii++) {
            cout << firstN[i*XMAX +ii];
            sum += AlphNum(firstN[i * XMAX + ii]);
        }
        worth[i] = sum * (i+1);
        final += worth[i];
        sum = 0;
        cout << endl;
    }
    cout << endl;
    cout << final;
    free(firstN);
    free(worth);
    names.close();
}


int AlphNum(char alpha) {                       //literally a switch A = 1, B = 2... Z = 26... boring... easy
    int number = 0;
    switch (alpha) {
    case 'A': {
        number = 1;
        break;
    }
    case 'B': {
        number = 2;
        break;
    }
    case 'C': {
        number = 3;
        break;
    }
    case 'D': {
        number = 4;
        break;
    }
    case 'E': {
        number = 5;
        break;
    }
    case 'F': {
        number = 6;
        break;
    }
    case 'G': {
        number = 7;
        break;
    }
    case 'H': {
        number = 8;
        break;
    }
    case 'I': {
        number = 9;
        break;
    }
    case 'J': {
        number = 10;
        break;
    }
    case 'K': {
        number = 11;
        break;
    }
    case 'L': {
        number = 12;
        break;
    }
    case 'M': {
        number = 13;
        break;
    }
    case 'N': {
        number = 14;
        break;
    }
    case 'O': {
        number = 15;
        break;
    }
    case 'P': {
        number = 16;
        break;
    }
    case 'Q': {
        number = 17;
        break;
    }
    case 'R': {
        number = 18;
        break;
    }
    case 'S': {
        number = 19;
        break;
    }
    case 'T': {
        number = 20;
        break;
    }
    case 'U': {
        number = 21;
        break;
    }
    case 'V': {
        number = 22;
        break;
    }
    case 'W': {
        number = 23;
        break;
    }
    case 'X': {
        number = 24;
        break;
    }
    case 'Y': {
        number = 25;
        break;
    }
    case 'Z': {
        number = 26;
        break;
    }
    default: {
        number = 0;
        break;
    }
    }
    return number;
}
int SortByAlpha(char* letters)                  //paired with a loop, this function sorts words alphabetically by comparing the first letter of a starting word and the first letter of the word "above" it in the array
{
    int n = 0;              //number of swaps
    char hold;
    for (int i = 0; i < YMAX-1; i++) {
        for (int ii = 0; ii < XMAX; ii++) {
            int pos1 = (AlphNum(letters[i * XMAX + ii]));
            int pos2 = (AlphNum(letters[(i + 1) * XMAX + ii]));
            if (pos1 > pos2) {                                  //if the first letter comes after the second
                for (int iii = 0; iii < XMAX; iii++) {
                    hold = letters[i * XMAX + iii];
                    letters[i * XMAX + iii] = letters[(i + 1) * XMAX + iii];
                    letters[(i + 1) * XMAX + iii] = hold;
                }              
                n++;
                ii = XMAX;
            }
            else if (pos1 < pos2) {
                ii = XMAX;
            }
            else if (((letters[(i + 1) * XMAX + ii]) == '\0') && (letters[i * XMAX + ii]) != '\0') {
                for (int iii = 0; iii < XMAX; ii++) {
                    hold = letters[i * XMAX + iii];
                    letters[i * XMAX + iii] = letters[(i + 1) * XMAX + iii];
                    letters[(i + 1) * XMAX + iii] = hold;
                }
                n++;
                ii = XMAX;
            }
        }
    }

    return n;               //using loop in main function, stop calling function if number of swaps is zero
}
// EP_42.cpp        Isaiah Campsall        October 21, 2022
/*
        The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

        1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

        By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. 
        For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. 
        If the word value is a triangle number then we shall call the word a triangle word.

        words.txt is a 16K text file containing nearly two-thousand common English words, 
        how many are triangle words?
*/

#include "EPHeader.h"

using namespace std;

int main()
{
    vector<string> words;
    int index = 0;
    string intermediate;
    ifstream input;
    input.open("words.txt");
    while (!input.eof()) {
        words.push_back("next");
        getline(input, words[index], '"');
        if (words[index] == "," || (words[index] == "")) {
            words.erase(words.begin() + index);
        }
        else {
            index++;
        }
    }
    input.close();
    vector<int> values(words.size());
    for (int i = 0; i < words.size(); i++) {
        for (int ii = 0; ii < words[i].size(); ii++) {
            values[i] += ((int)words[i][ii] - 64);

        }
        cout << words[i] << "     ";
        cout << values[i] << endl;
    }
    vector<int> triangles;
    for (int i = 0; i <= *max_element(values.begin(), values.end()); i++) {
        triangles.push_back(((double)i / 2) * (i + 1));
    }
    int answer = 0;
    for (int i = 0; i < values.size(); i++) {
        for (int ii = 0; ii < triangles.size(); ii++) {
            if (triangles[ii] == values[i]) {
                answer++;
            }
        }
    }
    cout << endl << answer;
}


/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #13: "Jeff Bezos' Daily Income" - Trianan - Dec 18/2021
    
           "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers
            (See problem_13_numbers.txt)."

	< ------ -= ======------ -= ======------ -= ======------ -= ======-------> N O T E S <------ -= ======------ -= ======------ -= ======------ -= ======------->

            - BigNum implementation might come in handy for this one (Dec 18/2021).

	*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

void read_addends(vector<vector<int>>& addends, string addends_filename) {
    // Reads large integer addends from text file, into vector of integer-vectors, each of 
    // which represent an individual addend.

    // Choosing file input.
    ifstream addends_stream{ addends_filename };
    while (!(addends_stream)) {
        addends_stream.close();
        cout << "File not found, please enter a new filename: ";
        cin >> addends_filename;
        addends_stream.open(addends_filename);
    }
    cout << addends_filename << " opened.\n";

    string addend_str;
    getline(addends_stream, addend_str);
    while (addends_stream) {
        cout << "\tAddend string: " << addend_str << " Digits: ";
        vector<int> addend;
        for (int i = 0; i < addend_str.size(); ++i) {
            char d = addend_str[i]; cout << d;
            if (isdigit(d)) {
                int dd = d - '0'; // Character '0' has the ASCII code of 48, and they're consecutively numbered.
                addend.push_back(dd);
            }
        }
        cout << '\n';
        addends.push_back(addend);
        getline(addends_stream, addend_str);
    }

    cout << addends_filename << " read successfully.\n\n";
}

// These may be wrapped in a BigNum add() function eventually:
int add_column(vector<vector<int>>& addends, int column_index, int carry = 0) {
    // Adds a column of digits from a vector of addends, including optional carry from previous row.
    int sum = 0;
    for (int i = 0; i < addends.size(); ++i)
        sum += addends[i][column_index];
    return sum + carry;
}

string add_BigNums(vector<vector<int>> addends) {

    string sum_str;

    vector<int> carry_row(addends[0].size(), 0);

    for (int i = 0; i < addends[0].size(); ++i) {
        int last_index = addends[0].size() - 1;

        int column_sum = add_column(addends, last_index - i); // Rightmost to left.
        while (column_sum >= 100) {
            column_sum -= 100;
            if (last_index - i >= 2)
                carry_row[last_index - i - 2] += 1;
            else {
                carry_row.insert(carry_row.begin(), 1); // Insert 1 at beginning of number, which can be added to.
                last_index += 1;
            }
        }
        while (column_sum >= 10) {
            column_sum -= 10;
            if (last_index - i >= 1)
                carry_row[last_index - i - 1] += 1;
            else {
                carry_row.insert(carry_row.begin(), 1); // Insert 1 at beginning of number, which can be added to.
                last_index += 1;             }

        }
    }

    return sum_str;
}








//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->
int main() {

    vector<vector<int>> addends;
    read_addends(addends, "problem_13_numbers.txt");
    cout <<"Sum of column 0: "<< add_column(addends, 0) << '\n';
    cout <<"\n\n\n"<< add_BigNums(addends)<<'\n';
    return 0;
}
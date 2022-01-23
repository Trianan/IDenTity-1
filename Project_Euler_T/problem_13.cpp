
/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #13: "Jeff Bezos' Daily Income" - Trianan - Jan 23/2022
    
           "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers
            (See problem_13_numbers.txt)."

	< ------ -= ======------ -= ======------ -= ======------ -= ======-------> N O T E S <------ -= ======------ -= ======------ -= ======------ -= ======------->

            - BigNum implementation might come in handy for this one (Dec 18/2021 - Trianan).

                - Nah. (Jan 16/2022 - Trianan)

            - Implemented reading the addends from a text file into a 2D int vector, with optional console printing. (Jan 16/2022 - Trianan)

            - Implemented sum_column(). (Jan 21/2022 - Trianan)

            - Started implemented sum_addends(); need to work on carry as a column addition can have a maximum sum of 9*50 = 450 (Jan 22/2022 - Trianan)

            - Implemented carrying operation successfully and sum_addends() in general. (Jan 23/2022 - Trianan)

	*/

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

vector<vector<int>> populate_numgrid(string filename, bool print=false) {
    vector<vector<int>> numgrid(1); // Dynamically allocated 2D array.
    ifstream digit_file{ filename };

    int i = 0;
    while (digit_file) {
        char c = digit_file.get();
        if (isdigit(c)) {
            int digit = c - 48; // Char value minus ASCII offset to get int.
            numgrid[i].push_back(digit);
        }
        if (iswspace(c)) {
            ++i; // Next row/number.
            vector<int> next_n;
            numgrid.push_back(next_n);
        }
    }

    if (print) {
        for (int i = 0; i<numgrid.size(); ++i) {
            vector<int> number = numgrid[i];

            cout << "\n\t";
            for (int digit : number) {
                cout << digit;
            }
            if (i != numgrid.size() - 1) cout << " +";
            else {
                cout << "\n=   \t";
                for (int i = 0; i < numgrid[0].size(); ++i)
                    cout << "-";
                cout << '\n';
            }
        }
    }
    return numgrid;
}

struct ColumnSum {
    // Represents the result of adding a column of digits; carry is for the next row.
    int sum = 0;
    int carry = 0;
};

ColumnSum sum_column(int column_i, const vector<vector<int>>& numgrid, int previous_carry=0){
    // Adds digits in a 2D int vector's given column; reduces it into a single digit and calculates the
    // carry for the next row.
    ColumnSum column_result;
    column_result.sum += previous_carry;
    for (int i = 0; i < numgrid.size(); ++i) {
        column_result.sum += numgrid[i][column_i];
    }
    while (column_result.sum >= 10) {
        column_result.sum -= 10;
        column_result.carry += 1;
    }

    return column_result;
}

string sum_addends(vector<vector<int>>& numgrid) {
    // Sums a block of addends with the same number of digits.
    string final_result = "";
    for (int digit : numgrid[0]) {
        final_result += '0';
    }

    int previous_carry = 0;
    for (int column_i = numgrid[0].size() - 1; column_i >= 0; --column_i) { // Count back from rightmost column to left.
        ColumnSum c_sum = sum_column(column_i, numgrid, previous_carry);
        final_result[column_i] = c_sum.sum + 48; // ASCII int-to-char offset.
        previous_carry = c_sum.carry;

        if (column_i == 0 && c_sum.carry != 0) { // Overflowing carry.

            final_result.insert(final_result.begin(), '0');
            for (vector<int>& number : numgrid)
                number.insert(number.begin(), 0);
            ++column_i;

        }
    }
    return final_result;
}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {

    vector<vector<int>> numgrid = populate_numgrid("problem_13_numbers.txt", true);

    cout<<"\t"<<sum_addends(numgrid) << '\n';

    return 0;
} 

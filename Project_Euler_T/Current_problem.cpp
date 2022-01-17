
/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #13: "Jeff Bezos' Daily Income" - Trianan - Dec 18/2021
    
           "Work out the first ten digits of the sum of the following one-hundred 50-digit numbers
            (See problem_13_numbers.txt)."

	< ------ -= ======------ -= ======------ -= ======------ -= ======-------> N O T E S <------ -= ======------ -= ======------ -= ======------ -= ======------->

            - BigNum implementation might come in handy for this one (Dec 18/2021 - Trianan).

                - Nah. (Jan 16/2022 - Trianan)

            - Implemented reading the addends from a text file into a 2D int vector, with optional console printing. (Jan 16/2022 - Trianan)

	*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


vector<vector<int>> populate_digit_matrix(string filename, bool print=false) {
    vector<vector<int>> digit_matrix(1); // Dynamically allocated 2D array.
    ifstream digit_file{ filename };

    int i = 0;
    while (digit_file) {
        char c = digit_file.get();
        if (isdigit(c)) {
            int d = c - 48; // Char value minus ASCII offset to get int.
            digit_matrix[i].push_back(d);
        }
        if (iswspace(c)) {
            ++i; // Next row/number.
            vector<int> next_n;
            digit_matrix.push_back(next_n);
        }
    }
    if (print) {
        for (int i = 0; i<digit_matrix.size(); ++i) {
            vector<int> number = digit_matrix[i];

            cout << "\n\t";
            for (int digit : number) {
                cout << digit;
            }
            if (i != digit_matrix.size() - 1) cout << " +";
            else {
                cout << "\n=   \t";
                for (int i = 0; i < digit_matrix[0].size(); ++i)
                    cout << "-";
                cout << '\n';
            }
        }
    }
    return digit_matrix;
}

struct column_sum {
    int sum = 0;
    int carry = 0;
};

column_sum add_column(){
    column_sum result;
    return result;
}


//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->



int main() {

    vector<vector<int>> digimatrx = populate_digit_matrix("problem_13_numbers.txt", true);

    return 0;
} 
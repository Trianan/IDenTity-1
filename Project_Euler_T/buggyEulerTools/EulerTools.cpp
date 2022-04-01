
/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  E U L E R  T O O L S  <=======------ -= ======------ -= ======------ -= ======------->

		EULERTOOLS: A set of tools developed for Project Euler problems.

			- class BigNum: a type developed for integers outside the range of standard integer types.

	< ------ -= ======------ -= ======------ -= ======------ -= ======-------> N O T E S <------ -= ======------ -= ======------ -= ======------ -= ======------->

			- Initial version of BigNum created (Dec 17/2021).
			- BigNum initializer further developed, with intention of creating representation as a stream.
			  Also worked on add() function for BigNum (Dec 18/2021).

              THIS NEEDS TO BE FIXED -LNK2005 ERROR W EulerTools.h that I cant be fucked to figure out rn.
	*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

namespace EulerTools {

    struct ColumnSum {
        // Represents the result of adding a column of digits; carry is for the next row.
        int sum = 0;
        int carry = 0;
    };

    ColumnSum sum_column(int column_i, const vector<string>& addends, int previous_carry = 0) {
        // Adds digits in a 2D int vector's given column; reduces it into a single digit and calculates the
        // carry for the next row.
        ColumnSum column_result;
        column_result.sum += previous_carry;
        for (int i = 0; i < addends.size(); ++i) {
            column_result.sum += addends[i][column_i] - '0';
        }
        while (column_result.sum >= 10) {
            column_result.sum -= 10;
            column_result.carry += 1;
        }

        return column_result;
    }

    string sum_addends(vector<string>& addends) {
        // Sums a block of addends represented as strings.
        string final_result = "";
        int most_digits = 0; // Makes the result the same length as the longest addend.
        for (string addend : addends)
            if (addend.size() > most_digits)
                most_digits = int(addend.size());
        for (int i = 0; i < most_digits; ++i)
            final_result += '0';

        for (string& addend : addends) { // Makes all addend string same length, allowing adding different length addends.
            string leading_zeroes = "";
            for (int i = 0; i < (most_digits - int(addend.size())); ++i) {
                leading_zeroes += '0';
            }
            addend = leading_zeroes + addend; // Inserts zeroes at left.
        }
        int previous_carry = 0;
        for (int column_i = int(addends[0].size()) - 1; column_i >= 0; --column_i) { // Count back from rightmost column to left.
            ColumnSum c_sum = sum_column(column_i, addends, previous_carry);
            final_result[column_i] = c_sum.sum + 48; // ASCII int-to-char offset.
            previous_carry = c_sum.carry;

            if (column_i == 0 && c_sum.carry != 0) { // Overflowing carry.

                final_result.insert(final_result.begin(), '0');
                for (string& number : addends)
                    number = '0' + number;//.insert(number.begin(), 0);
                ++column_i;

            }
        }
        return final_result;
    }
};


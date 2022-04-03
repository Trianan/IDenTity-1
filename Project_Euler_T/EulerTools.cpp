/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  E U L E R   T O O L S  <=======------ -= ======------ -= ======------ -= ======------->
    Trianan - APR 1/2022

    - A library composed of tools I've built to solve Project Euler problems.

        - Functions for adding digit strings of any reasonable size.

    < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->
*/  

#include "EulerTools.h"

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

namespace EulerTools {



    // BASIC TOOLS:
    vector<int> get_factors(int n, bool console_output, bool exclude_n) {
        // Returns a list of factors of a given integer.
        vector<int>factors;
        int search_floor = 0;
        for (int i = n; i > search_floor; --i) // Increases search floor as the function finds factors to avoid unnecessary computation.
            if (n % i == 0) {
                search_floor = n / i;
                if (i == n && exclude_n)
                    factors.push_back(n / i);
                else { 
                    factors.push_back(i);
                    factors.push_back(n/i);
                }
            }
        if (console_output) {
            cout << "Factors of " << n << ":\n\n";
            for (int factor : factors)
                cout << "\t" << factor << '\n';
            cout << '\n';
        }
        return factors;
    }
    int sum_factors(int n) {
        // Returns the sum of the factors of a given integer.
        int sum = 0;
        for (int factor : EulerTools::get_factors(n, false, true))
            sum += factor;

        return sum;
    }
    vector<int> generate_integer_subset(int min, int max) {
        // Generates a vector of consecutive integers from min to max.
        vector<int> subset;
        for (int i = min; i <= max; ++i)
            subset.push_back(i);
        return subset;
    }

    // TOOLS FOR NUMBER-STRINGS:
    string not_a_number = "!!!";

    struct ColumnSum {
        // Represents the result of adding a column of digits; carry is for the next row.
        int sum = 0;
        int carry = 0;
    };
    ColumnSum sum_column(int column_i, const vector<string>& addends, int previous_carry) {
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
    string sum_addends(string a, string b) {
        // Overload for direct adding of two string for convenience:
        vector<string>addends{ a,b };
        return sum_addends(addends);
    }

    string factorial(int n) {
        // Returns a string of the decimal expansion of factorial numbers given as integers.
        string result = "1";
        for (int i = 1; i <= n; ++i) {

            vector<string>term_addends;
            for (int ii = 0; ii < i; ++ii)
                term_addends.push_back(result);

            result = EulerTools::sum_addends(term_addends);
        }
        return result;
    }
    string factorial(string& n) {
        // Since most of these functions work with strings; it makes sense to include string arguments for this:
        bool is_number = true;
        for (char digit : n)
            if (!isdigit(digit))
                is_number = false;

        if (is_number) {
            stringstream ss{ n };
            int int_n; ss >> int_n;
            return factorial(int_n);
        }
        else {
            cout<<"\n\tfactorial() only accepts integers or digit-strings as arguments!\n";
            return not_a_number;
        }
    }

    int sum_digits(string& numstring) {
        // Converts chars in numstring to ints, then sums them.
        int sum = 0;
        for (char c : numstring) {
            int digit = c - 48;
            sum += digit;
        }
        return sum;
    }
};

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->
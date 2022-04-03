/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #25: "Fat Fibonacci" - Trianan - Apr 3/2022

		"The Fibonacci sequence is defined by the recurrence relation:
         Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

         Hence the first 12 terms will be:
            F1 = 1
            F2 = 1
            F3 = 2
            F4 = 3
            F5 = 5
            F6 = 8
            F7 = 13
            F8 = 21
            F9 = 34
            F10 = 55
            F11 = 89
            F12 = 144

         The 12th term, F12, is the first term to contain three digits.
         What is the index of the first term in the Fibonacci sequence to contain 1000 digits?"

	< ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;

int main() {

    string previous_term = "0";
    string current_term = "1";
    int current_index = 1;

    while (current_term.size() < 1000) {
        string term = EulerTools::sum_addends(current_term, previous_term);
        previous_term = current_term;
        current_term = term;
        ++current_index;
    }
    cout << "\n\n\n" << current_term << "\n\nIndex: " << current_index;

	return 0;
}
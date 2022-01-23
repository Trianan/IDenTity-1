
/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #14: "Hailstone Numbers" - Trianan - Jan 23/2022
    
           "The following iterative sequence is defined for the set of positive integers:

                n -> n/2 (n is even)
                n -> 3n + 1 (n is odd)

            Using the rule above and starting with 13, we generate the following sequence:

                13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

            It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

            Which starting number, under one million, produces the longest chain?

            NOTE: Once the chain starts the terms are allowed to go above one million."

	*/

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

using integer = unsigned long int;

void generate_sequence(integer n, vector<integer>& sequence) {
    sequence.push_back(n);
    while (true) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = (3 * n) + 1;
        sequence.push_back(n);
        if (n == 1)
            break;
    }
    return;   
}

void find_max_sequence(integer max_n) {
    vector<integer> max_sequence;
    for (integer n = 1; n <= max_n; ++n) {
        vector<integer> current_sequence;
        generate_sequence(n, current_sequence);
        if (current_sequence.size() > max_sequence.size())
            max_sequence = current_sequence;
    }
    cout << "Size of largest sequence: " << max_sequence.size() << "\nStarting number: "<<max_sequence[0]<<"\n\n";
    for (integer i = 0; i < max_sequence.size(); ++i)
        cout << max_sequence[i] << '\n';
}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {

    find_max_sequence(1000000);

    return 0;
} 

/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  P R O J E C T  E U L E R  <=======------ -= ======------ -= ======------ -= ======------->

	PROBLEM #18: "Pyramid Treasure Tunnel" - Trianan - Apr 1/2022

		   "By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

						   3
						  7 4
						 2 4 6
						8 5 9 3

				That is, 3 + 7 + 4 + 9 = 23.

			Find the maximum total from top to bottom of the triangle below:

			              75
			             95 64
			            17 47 82
			           18 35 87 10
			          20 04 82 47 65
			         19 01 23 75 03 34
			        88 02 77 73 07 63 67
			       99 65 04 28 06 16 70 92
			      41 41 26 56 83 40 80 70 33
			     41 48 72 33 47 32 37 16 94 29
			    53 71 44 65 25 43 91 52 97 51 14
			   70 11 33 28 77 73 17 78 39 68 17 57
			  91 71 52 38 17 14 91 43 58 50 27 29 48
			 63 66 04 68 89 53 67 30 73 16 69 87 40 31
			04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

			NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. 
			However, Problem 67, is the same challenge with a triangle containing one-hundred rows; 
			it cannot be solved by brute force, and requires a clever method! ;o)"

    < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#include "EulerTools.h"

using namespace std;



//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

using Vec2D = vector<vector<int>>;

Vec2D generate_numtri(string numtri_filename, bool console_output=false) {
	// Generates a triangular matrix with numbers from a text file of numbers.
	ifstream numtri_ifs{ numtri_filename };

	vector<vector<int>> numtri;
	int current_n = 0;
	int current_row = 1;

	while (numtri_ifs) {
		vector<int>row;
		for (int i = 0; i < current_row; ++i) {
			if (numtri_ifs >> current_n)
				row.push_back(current_n);
		}
		numtri.push_back(row);
		++current_row;
	}

	// Optional console output for debugging.
	if (console_output) {
		for (vector<int> row : numtri) {
			for (int n : row)
				cout << n << " ";
			cout << '\n';
		}
	}

	return numtri;
}

class Node {
	// Class representing a node on a given 2D-graph.
public:
	Node(int r, int e, Vec2D f);
	bool is_valid();
	bool visited = false; 

private:
	int nth_row;
	int nth_element;
	Vec2D field;
};
Node::Node(int r, int e, Vec2D f) : nth_row(r), nth_element(e), field(f) {}
bool Node::is_valid() {
	// Checks if the position exists on the given field.
	bool validity = true;
	if (nth_row < 0 || field.size() < nth_row)
		validity = false;

	else if (nth_element < 0 || field[nth_row].size() < nth_element)
		validity = false;
	return validity;
}


void initialize_tentative_values(Vec2D)








//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {
	vector<vector<int>> number_triangle = generate_numtri("problem_18_triangle.txt", true);

	return 0;
}
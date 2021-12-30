/*
	<-------=======-------=======-------=======-------=======>  P R O J E C T  E U L E R  <=======-------=======-------=======-------=======------->

		PROBLEM #11: "Productive Word Search" - Trianan - Dec 12/2021

		"In the 20×20 grid below, four numbers along a diagonal line have been marked in red (obviously not visible here).

			08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
			49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
			81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
			52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
			22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
			24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
			32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
			67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
			24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
			21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
			78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
			16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
			86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
			19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
			04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
			88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
			04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
			20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
			20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
			01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

		The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
		What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?"

	<-------=======-------=======-------=======-------=======-------> N O T E S <-------=======-------=======-------=======-------=======------->

		Movement:
			-Horizontal movement may be simulated by putting the grid into a vector and adding/subtracting 1 to the index of the current element.
			-Vertical movement may be simulated by ... adding/subtracting 20 to the index of the current element.
			-Positive-slope diagonal movement ... adding/subtracting 19 to the index.
			-Negative-slope diagonal movement .. adding/subtractng 21 to the index.
			-Let the absolute value of the integer used to achieve these be called the DIRECTION-FACTOR.
			-Direction-factor may likely be generalized for all finite grids.

		Searching:
			-Group three numbers by the fact that their indices are seperated by a common direction-factor.
				(e.g. the indices 0, 21, 42 are separated by the common direction-factor of 21, and are therefore negative-diagonal adjacent elements).
			-Since multiplication is commutative, only one of each pair of directions (e.g. right and left) is needed to find the greatest product.
			-Must be a check for out-of-range indices when searching; this is how search will conclude for a given direction.
			-Grouping of numbers may either be explicitely done with a vector, or a function that keeps track of the indices of each consecutive element.

		To-Do:
			-The vertical and horizontal search functions can probably be combined into one function such that the function calculates both
				inside one set of loops.

*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int horizontal_search(int (&numgrid)[20][20], int factors, int columns, int rows) {
	// Returns greatest product of a number of horizontally adjacent entries in a 2D array.
	int greatest_product = 1;
	int x = 0;
	int y = 0;

	while (y < rows) {
		while (x + (factors - 1) < columns) { // Ensures first index in sequence will be 4th last in row.
					// "(factors - 1)" because "x" is included in number of factors and counted already.
			int current_product = 1;
			for (int i = 0; i < factors; ++i) // Multiplies the first in sequence with following 4 integers.
				current_product *= numgrid[y][x + i];
			if (current_product > greatest_product)
				greatest_product = current_product;
			++x;
		}
		x = 0; // Return to start of 
		++y;   // row on next line.
	}
	return greatest_product;
}

int vertical_search(int(&numgrid)[20][20], int factors, int columns, int rows) {
	// Returns greatest product of a number of vertically adjacent entries in a 2D array.
	int greatest_product = 1;
	int x = 0;
	int y = 0;

	while (x < columns) {
		while (y + (factors - 1) < rows) {
			int current_product = 1;
			for (int i = 0; i < factors; ++i)
				current_product *= numgrid[y + i][x];
			if (current_product > greatest_product)
				greatest_product = current_product;
			++y;
		}
		y = 0;
		++x;
	}
	return greatest_product;
}

int diagonal_search_pos(int(&numgrid)[20][20], int factors, int columns, int rows) {
	// x-index must start at numgrid[y][3], because a 4-factor product cannot be made in a 
	// positive diagonal line at x-indices less than three, or any x-index past the y-index of 4 less
	// than the last y-index.
	int greatest_product = 1;
	int x_offset = (factors - 1); // Factors in diagonals that are less than 4
	int x = x_offset;
	int y = 0;
	int max_y = rows - (factors - 1);

	while (y < max_y ) {
		while (x < columns) { // y-indices less than 4 away from last cannot form 4-element diagonal line.
			int current_product = 1;
			for (int i = 0; i < factors; ++i)
				current_product *= numgrid[y + i][x - i]; // Down and left one entry.
			if (current_product > greatest_product)
				greatest_product = current_product;
			++x;
		}
		x = x_offset;
		++y;
	}
	return greatest_product;
}

int diagonal_search_neg(int(&numgrid)[20][20], int factors, int columns, int rows) {
	// x-index must be limited past numgrid[y][columns - factors], to
	// filter negative diagonals with elements less than 4.
	int greatest_product = 1;
	int x_limit = (columns - factors + 1); // Factors in diagonals that are less than 4
	int x = 0;
	int y = 0;
	int max_y = rows - (factors - 1); // Factors in diagonals that are less than 4

	while (y < max_y) {
		while (x < x_limit) { // y-indices less than 4 away from last cannot form 4-element diagonal line.

			int current_product = 1;
			for (int i = 0; i < factors; ++i)
				current_product *= numgrid[y + i][x + i]; // Down and right one entry.
			if (current_product > greatest_product)
				greatest_product = current_product;
			++x;
		}
		x = 0;
		++y;
	}
	return greatest_product;
}



int main() {
	const string numgrid_raw =
		"08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
		"49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
		"81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
		"52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
		"22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
		"24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
		"32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
		"67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
		"24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
		"21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
		"78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
		"16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
		"86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
		"19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
		"04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
		"88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
		"04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
		"20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
		"20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
		"01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";
	stringstream numgrid_stream{ numgrid_raw };

	const int rows = 20;
	const int columns = 20;
	int numgrid_matrix[rows][columns];

	int x = 0;
	for (int y = 0; y < rows; ++y) { // For each row from 0-19...
		while (x<columns) { // ...and for each element in the row (column index)...
			int n; numgrid_stream>>n;  // ...read each integer from input number grid...
			numgrid_matrix[y][x] = n; // ...and write it to each position in matrix.
			++x;
		}
		x = 0; // Reset column counter.
	}

	for (int y = 0; y < rows; ++y) { // Outputs number grid in original formatting.
		while (x < columns) {
			cout <<setw(3)<<left<< numgrid_matrix[y][x];
			++x;
		}
		cout << '\n';
		x = 0;
	}

	long int gh = horizontal_search(numgrid_matrix, 4, rows, columns);
	long int gv = vertical_search(numgrid_matrix, 4, rows, columns);
	long int dp = diagonal_search_pos(numgrid_matrix, 4, rows, columns);
	long int dn = diagonal_search_neg(numgrid_matrix, 4, rows, columns);

	cout << "Greatest horizontal product: " << gh << '\n';
	cout << "Greatest vertical product: " << gv << '\n';
	cout << "Greatest positive-slope diagonal product: " << dp << '\n';
	cout << "Greatest positive-slope diagonal product: " << dn << '\n';

	vector<long int> v { gh, gv, dp, dn };
	long int greatest_product = 1;
	for (long int n : v) {
		if (n > greatest_product) greatest_product = n;
	}
	cout << "GREATEST PRODUCT:\n\t\t---> " << greatest_product << "\n\n";



	return 0;
}
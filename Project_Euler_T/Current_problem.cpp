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
#include <Windows.h>

using namespace std;

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

struct Node {
	Node() {};
	Node(int v) { value = v; };
	Node(int v, int r, int i);
	const bool operator==(Node& b);
	const bool operator!=(Node& b);

	void print();

	int value = 0;
	int row = 0;
	int index = 0;

	int t_value = 0;
	int t_row = 0;
	int t_index = 0;

	bool unvisited = true;
};
Node::Node(int v, int r, int i) : value(v), row(r), index(i) {}
const bool Node::operator==(Node& b) {
	// Compares two nodes through their position.
	if (row == b.row && index == b.index)
		return true;
	else return false;
}
const bool Node::operator!=(Node& b) {
	return !(operator==(b));
}
void Node::print() {
	cout << "Node: (" << row << '.' << index << ")   Value: " << value
		<< "\nT-Node: (" << t_row << ',' << t_index << ")   T-Value: " << t_value
		<< "\nUnvisited: " << unvisited << "\n\n";
	return;
}

using Network = vector<vector<Node>>;

void print_network(Network& network, bool verbose = false, vector<Node*> marks = {}) {
	for (vector<Node>& row : network) {
		for (Node& n : row) {
			cout <<"[ "<< n.value << " (" << n.row << ',' << n.index<<')';
			if (verbose) {
				cout << " | " << n.t_value;
				for(Node* mark : marks)
					if (n == *mark)
						cout << " V";
				if (n.unvisited)
					cout << " O";
				else cout << " 0";
			}
			cout << " ]\t";
		}
		cout << "\n\n";
	}
}
void print_simple_network(Network& network, Node* current_node) {
	// Prins the current state of the network in a simple format.
	for (vector<Node>& row : network) {
		for (Node& n : row) {
			if (n == (*current_node))
				cout << "X ";
			else
				if (n.unvisited)
					cout << "o ";
				else cout << ". ";
		}
		cout << '\n';
	}
}
void print_simple_path(Network& network, vector<Node*> path = {}) {
	// Prints the path in a simple format.
	for (vector<Node>& row : network) {
		for (Node& n : row) {
			bool is_step = false;
			for (Node* step : path)
				if (n == (*step))
					is_step = true;
			if (is_step)
				cout << "X ";
			else cout << ". ";
		}
		cout << '\n';
	}
}

Network generate_triangle(string& numtri_filename, bool console_output = false) {
	// Generates a triangular matrix with numbers from a text file of numbers.
	ifstream file_input{ numtri_filename };
	Network number_triangle;

	int value = 0;
	int current_row = 1;
	while (file_input) {

		vector<Node>row;
		for (int i = 0; i < current_row; ++i)
			if (file_input >> value)
				row.push_back(Node{value, current_row-1, i});

		number_triangle.push_back(row);
		++current_row;
	}
	number_triangle.pop_back();

	// Optional console output for debugging.
	if (console_output) {
		print_network(number_triangle);
	}

	return number_triangle;
}

vector<Node*> get_neighbors(const Node& node, Network& network) {
	// This gets the next available nodes according to the rules of Problem #18 specifically.
	vector<Node*> neighbors{};
	if (node.row < network.size()-1) {
		int r = node.row;
		int i = node.index;

		Node* n1 = &network[r + 1][i];
		Node* n2 = &network[r + 1][i + 1];
		neighbors.push_back(n1);
		neighbors.push_back(n2);
	}
	return neighbors;
}

Node* next_node(Network& network, bool ignore_visited=true) {
	// Returns a pointer to the next unvisited node in the network according to highest t-value.
	Node empty_node;
	Node* greatest_node_ptr = &empty_node; // Initializes node pointer to address an empty node with zero for every value.

	for (int r = 0; r < network.size(); ++r)  
		for (int i = 0; i < network[r].size(); ++i)
			if (network[r][i].t_value > (*greatest_node_ptr).t_value && (network[r][i].unvisited || !ignore_visited))
				greatest_node_ptr = &network[r][i]; // Sets node pointer to node with greatest t_value so far.

	return greatest_node_ptr;
}

vector<Node*> find_path(Node& start_node, Network& network) {
	start_node.t_value = start_node.value; // Initializes the start_node.
	start_node.t_row = start_node.row; // The starting node is always initializes with the values of itself.
	start_node.t_index = start_node.index;
	Node* current_node = &start_node; // Current_node is a pointer to each actual node in the network, not a copy.

	bool complete = false;
	vector<Node*> mark_current{ current_node };
	while (!complete) {

		for (Node* neighbor : get_neighbors(*current_node, network)) {
			int calculated_t_value = (*current_node).t_value + (*neighbor).value; // Highest path to current node + distance to neighbor = neighbor's t-value through current node.
			if (calculated_t_value > (*neighbor).t_value) {
				(*neighbor).t_value = calculated_t_value;
				(*neighbor).t_row = (*current_node).row; // These two are for tracking the path which the TD was obtained.
				(*neighbor).t_index = (*current_node).index;
			}
		}
		(*current_node).unvisited = false;

		bool complete = true; // Continues until all nodes are visited.
		for (vector<Node>& row : network)
			for (const Node& node : row) {
				if (node.unvisited) complete = false;
			}

		print_simple_network(network, current_node);
		Sleep(30);

		if (complete) { // Traces out and returns a pointer vector of nodes forming the final path.
			current_node = next_node(network, false); // Sets current_node to highest t_value node.
			vector<Node*> path;
			while (true) {
				path.push_back(current_node); // Trace back through nodes access by their location, and pushing each current node to the path-list.
				current_node = &(network[(*current_node).t_row][(*current_node).t_index]);
				if (*current_node == start_node) { // Done; push back the last node and return the finished list.
					path.push_back(current_node);
					return path;
				}
			}
		}
		else
			current_node = next_node(network);
		//cout << "\tNEXT: ("<<(*current_node).row<<','<<(*current_node).index<<") ...\n";
		system("cls");
	}
}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

int main() {
	string filename = "problem_18_triangle.txt";
	Network numtri = generate_triangle(filename, true);

	vector<Node*> path = find_path(numtri[0][0], numtri);

	int nth_step = 1;
	for (Node* step_ptr : path) {
		cout << "\tSTEP #" << nth_step << "\n";
		(*step_ptr).print();
		cout << "\n";
		++nth_step;
	}
	

	print_network(numtri, true, path);
	cout << "\n\n";
	print_simple_path(numtri, path);











	return 0;
}
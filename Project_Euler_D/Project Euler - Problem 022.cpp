// Project Euler - Problem 022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Using names.txt(right click and 'Save Link/Target As...'), a 46K text file containing over five - thousand first names, begin by sorting 
// it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in 
// the list to obtain a name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in 
// the list. So, COLIN would obtain a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?

#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	// initialize answer to 0
	int answer = 0;

	// open file containing list of names
	ifstream file("names.txt");

	// report error if file cannot open
	if (!file.is_open())
	{
		cout << "Unable to open file";
		return -1;
	}

	// initalize a vector of names, and a string to breifly hold each name
	vector<string> names;
	string name;

	// put each name into the vector, using a comma as an indicator to move to the next space in the vector
	while (getline(file, name, ','))
	{
		names.push_back(name);
	}

	// find the length of the vector
	int length = names.size();

	// sort names alphabetically
	sort(names.begin(), names.end());

	// run through each name in the list
	for (int i = 0; i < names.size(); i++)
	{
		// strip the quotations around the current name
		names[i].erase(remove(names[i].begin(), names[i].end(), '"'), names[i].end());

		// mulitply all character values by the name's position and add to final answer (ASCII for 'A' is 65, so subtract 64 to get numeric value)
		for (int j = 0; j < names[i].length(); j++)
		{
			answer += (i + 1)*(names[i][j] - 64);
		}
	}

	// output answer
	cout << answer;

	return 0;
}
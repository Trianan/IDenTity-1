/*
Project Euler - Problem 022.cpp : This file contains the 'main' function. Program execution begins and ends there.

Using names.txt(right click and 'Save Link/Target As...'), a 46K text file containing over five - thousand first names, begin by sorting 
it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in 
the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in 
the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file ?
*/

#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	int answer = 0;

	ifstream file("names.txt");

	if (!file.is_open())
	{
		cout << "Unable to open file";
		return -1;
	}

	vector<string> names;
	string name;

	while (getline(file, name, ','))
	{
		names.push_back(name);
	}

	int length = names.size();

	sort(names.begin(), names.end());

	for (int i = 0; i < names.size(); i++)
	{
		names[i].erase(remove(names[i].begin(), names[i].end(), '"'), names[i].end());

		for (int j = 0; j < names[i].length(); j++)
		{
			answer += (i + 1)*(names[i][j] - 64);
		}
	}

	cout << answer;

	return 0;
}
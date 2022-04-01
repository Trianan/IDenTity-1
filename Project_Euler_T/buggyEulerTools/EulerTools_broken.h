#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "EulerTools.cpp"

using namespace std;

namespace EulerTools {
	struct ColumnSum;
	ColumnSum sum_column(int, const vector<string>&, int);
	string sum_addends(vector<string>&);
}



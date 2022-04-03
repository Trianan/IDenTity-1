/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  E U L E R   T O O L S  <=======------ -= ======------ -= ======------ -= ======------->
	Trianan - APR 3/2022

		-Header file for EulerTools.cpp and my Project Euler solutions.

	< ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======-------> */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->

namespace EulerTools {

	// BASIC TOOLS:
	std::vector<int> get_factors(int n, bool console_output=false, bool exclude_n=false);
	int sum_factors(int n);
	std::vector<int> generate_integer_subset(int min, int max);
	

	// TOOLS FOR NUMBER-STRINGS:
	struct ColumnSum;
	ColumnSum sum_column(int column_i, const std::vector<std::string>& addends, int previous_carry = 0);
	std::string sum_addends(std::vector<std::string>& addends);
	std::string sum_addends(std::string a, std::string b);

	std::string factorial(int n);
	std::string factorial(std::string& n);

	int sum_digits(std::string& numstring);

}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->
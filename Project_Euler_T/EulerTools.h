/*  <------ -= ======------ -= ======------ -= ======------ -= ======>  E U L E R   T O O L S  <=======------ -= ======------ -= ======------ -= ======------->
	Trianan - APR 1/2022

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

	struct ColumnSum;
	ColumnSum sum_column(int column_i, const std::vector<std::string>& addends, int previous_carry = 0);
	std::string sum_addends(std::vector<std::string>& addends);

}

//  < ------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------ -= ======------->
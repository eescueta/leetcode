#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
*/

/*
16
8
5
-4
*/

bool isPowerOfFour(int n) {
	if (n == 1)
		return true;

	if (n < 4 || n % 2 != 0)
		return false;
	
	double log_4_ns = log(n) / log(2.0);
	int log_4_n = (int)log_4_ns;

	// validate log is a whole number
	if (log_4_ns != log_4_n)
		return false;

	return (log_4_n % 2 == 0);
}
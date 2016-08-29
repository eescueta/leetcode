#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an integer, write a function to determine if it is a power of two.
*/

/*
0
1
2
4
-2
8
16
32
3
95
101
150564
*/

bool isPowerOfTwo(int n) {
	if (n == 1)
		return true;

	if (n < 2)
		return false;

	int log_2_n = (int)log(INT_MAX) / log(2.0);
	int biggestPossiblePowerOf2 = (int)pow(2, log_2_n);

	// ONLY WORKS FOR PRIME POWERS
	return biggestPossiblePowerOf2 % n == 0;
}
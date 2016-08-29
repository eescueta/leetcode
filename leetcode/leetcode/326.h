#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?
*/

/*
27
3
9
81
1
2
82
10
28
243
0
*/

bool isPowerOfThree(int n) {
	if (n == 1)
		return true;

	if (n < 3)
		return false;

	int log_3_n = (int)log(INT_MAX) / log(3.0);
	int biggestPossiblePowerOf3 = (int) pow(3, log_3_n);

	// ONLY WORKS FOR PRIME POWERS
	return biggestPossiblePowerOf3 % n == 0;
}
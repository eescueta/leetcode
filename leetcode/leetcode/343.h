#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include "Solution.h"

using namespace std;

/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/

/*
2
3
4
5
7
8
9
10
6
11
58
*/

int integerBreak(int n) {
	int result = 1;

	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;

	while (n > 4)
	{
		n -= 3;
		result *= 3;
	}

	result *= n;

	return result;
}
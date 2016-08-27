#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.
*/

/*
1
2
-2
2
5
3
4
1
*/

static int getSum(int a, int b) {\
	int carry = a & b;
	int sum = a ^ b;

	while (carry != 0)
	{
		carry <<= 1;
		int carryTemp = carry & sum;
		sum = carry ^ sum;
		carry = carryTemp;
	}

	return sum;
}
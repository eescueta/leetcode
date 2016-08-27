#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:
A naive implementation of the above process is trivial. Could you come up with other methods?
What are all the possible results?
How do they occur, periodically or randomly?
*/

/*
0
38
11
65336
*/

int addDigits(int num) {
	if (num % 9 == 0 && num != 0)
		return 9;
	else
		return num % 9;
}
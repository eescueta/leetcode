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
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
[1,2,3]
[1]
[1,2]
[1,2,3,4]
*/

void generateParenthesisHelper(int leftRemaining, int rightRemaining, string s, vector<string>& res)
{
	if (leftRemaining == 0 && rightRemaining == 0) res.push_back(s);
	if (leftRemaining > 0) generateParenthesisHelper(leftRemaining - 1, rightRemaining + 1, s + "(", res);
	if (rightRemaining > 0) generateParenthesisHelper(leftRemaining, rightRemaining - 1, s + ")", res);
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	generateParenthesisHelper(n, 0, "", res);
	return res;
}


// OR ITERATIVE (more memory)

/*f(0) : ""

f(1) : "("f(0)")"

f(2) : "("f(0)")"f(1), "("f(1)")"

f(3) : "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"

So f(n) = "("f(0)")"f(n - 1), "("f(1)")"f(n - 2) "("f(2)")"f(n - 3) ... "("f(i)")"f(n - 1 - i) ... "(f(n-1)")*/
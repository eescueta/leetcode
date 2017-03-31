#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_set>
#include "Solution.h"

using namespace std;

/*
Total Accepted: 35863
Total Submissions: 102672
Difficulty: Hard
Contributors: Admin
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

/*
"()())()"
"(a)())()"
")("
""
"((()())()"
*/

// forgot pair the first time
void removeHelper(int pair, int remove_left, int remove_right, int curr_index, unordered_set<string>& results, const string& s, string curr_result)
{
	// if pair is negative at any time, end the recursive calls
	// forgot this
	if (pair < 0)
		return;

	if (curr_index == s.length() )
	{
		if (pair == 0 && remove_left == 0 && remove_right == 0)
			results.insert(curr_result);

		return;
	}

	if (s[curr_index] == '(')
	{
		if (remove_left > 0)
			removeHelper(pair, remove_left - 1, remove_right, curr_index + 1, results, s, curr_result);

		removeHelper(pair+1, remove_left, remove_right, curr_index + 1, results, s, curr_result + '(');
	}
	else if (s[curr_index] == ')')
	{
		if (remove_right > 0)
			removeHelper(pair, remove_left, remove_right - 1, curr_index + 1, results, s, curr_result);

		removeHelper(pair-1, remove_left, remove_right, curr_index + 1, results, s, curr_result + ')');
	}
	else
		removeHelper(pair, remove_left, remove_right, curr_index + 1, results, s, curr_result + s[curr_index]);

}

vector<string> removeInvalidParentheses(string s) {
	int remove_left = 0;
	int remove_right = 0;

	unordered_set<string> results;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			remove_left++;
		}
		else if (s[i] == ')')
		{
			if (remove_left > 0)
				remove_left--;
			else
				remove_right++;
		}
	}
	
	removeHelper(0, remove_left, remove_right, 0, results, s, "");
	return vector<string>(results.begin(), results.end());
}
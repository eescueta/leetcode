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
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/*
"aa"
"a"
"aa"
"aa"
"aaa"
"aa"
"aa"
"a*"
"aa"
".*"
"ab"
".*"
"aab"
"c*a*b*"
"ab"
"a*b.*y"
"aby"
"a*b.*y"
"by"
"a*b.*y"
"bay"
"a*b.*y"
""
"a*"
""
"a*a"
""
"a*a*"
"aaaaaaaaaaaaab"
"a*a*a*a*a*a*a*a*a*a*c"
"ab"
".*.."
"aab"
"b.*"
"aaa"
".*"
*/


// cleaner solution

bool isMatch(string s, string p)
{
	if (s == p) return true;
	if (p == "") return false;

	//vector<vector<bool>> results(vector<bool>(s.size() + 1, false), p.size() + 1);
	vector<vector<bool>> results(p.size() + 1, vector<bool>(s.size() + 1, false));
	results[0][0] = true;
	results[1][0] = false;

	// setting first column
	for (int i = 2; i < p.size() + 1; i++)
	{
		if (p[i-1] == '*')
			results[i][0] = results[i - 2][0];
		else
			results[i][0] = false;
	}

	for (int i = 1; i < results.size(); i++)
	{
		for (int j = 1; j < results[0].size(); j++)
		{
			if (s[j - 1] == p[i - 1] || (p[i - 1] == '.'))
				results[i][j] = results[i - 1][j - 1];
			else if (p[i - 1] == '*')
			{
				bool res = results[i - 1][j] || results[i - 2][j];
				if (j > 1 && (s[j - 1] == p[i - 2] || p[i - 2] == '.')) 
					res = res || results[i - 1][j - 1];

				if (p[i - 2] == '.')
					res = res || results[i][j - 1];

				results[i][j] = res;
			}

		}
	}


	return results.back().back();
}


bool isMatchOld(string s, string p) {
	if (s == p) return true;

	if (p == "" && s != "") return false;
	if (s == "")
	{
		if (p.length() >= 2 && p[1] == '*')
			return isMatchOld(s, p.substr(2));
		else
			return false;
	}

	if (s[0] == p[0] || p[0] == '.')
	{
		if (p.size() == 1 || p[1] != '*')
		{
			return isMatchOld(s.substr(1), p.substr(1));
		}
		else

		{
			return isMatchOld(s.substr(1), p.substr(2)) || isMatchOld(s, p.substr(2)) || isMatchOld(s.substr(1), p);
			//return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p) || isMatch(s.substr(1), p.substr(2));
		}
	}

	if (p.length() > 1 && p[1] == '*')
	{
		return isMatchOld(s, p.substr(2));
	}

	return false;
}
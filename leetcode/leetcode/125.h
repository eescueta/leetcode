#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>
#include <cctype>

using namespace std;

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
"A man, a plan, a canal: Panama"
"race a car"
*/


bool isPalindrome(string s) {
	int L = 0;
	int R = s.length() - 1;

	while (L < R)
	{
		if (!isalnum(s[L]))
		{
			L++;
			continue;
		}
		if (!isalnum(s[R]))
		{
			R--;
			continue;
		}

		if (tolower(s[L]) != tolower(s[R]))
			return false;
		else
		{
			L++;
			R--;
		}
	}
	return true;
}
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example,
Given s = "Hello World",
return 5.
*/

/*
""
"hello"
"hello world"
"hello hi world"
"hello hi "
" a"
*/

int lengthOfLastWord(string s) {
	if (s == "")
		return 0;

	int itr = s.length() - 1;
	int count = 0;
	
	// move past the spaces
	while (s[itr] == ' ')
	{
		itr--;
	}

	// count the last word
	while (s[itr] != ' ' && itr > 0)
	{
		itr--;
		count++;
	}

	// add last char if first word is the last word
	if (itr == 0 && s[itr] != ' ')
		count++;

	return count;
}
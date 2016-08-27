#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;



/*
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
*/

/*
"hello"
""
"a"
"aba"
"bab"
"123456"
*/
//

static string reverseString(string s) {
	string rev = "";
	
	// backwards loop
	for (int i = s.length() - 1; i >= 0; i--)
	{
		rev += s[i];
	}

	return rev;
}

#endif // ADD_H_INCLUDED
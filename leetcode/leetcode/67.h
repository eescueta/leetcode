#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
"0"
"0"
"11"
"1"
"111"
"001"
"111"
"111"
*/


string addBinary(string a, string b) {
	// pad strings
	while (a.length() < b.length())
		a = "0" + a;

	while (b.length() < a.length())
		b = "0" + b;

	string result = "";
	
	bool carry = false;;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		string digit;

		if (a[i] == '0' && b[i] == '0')
		{
			if (carry)
			{
				carry = false;
				digit = "1";
			}
			else
				digit = "0";
		}
		else if (a[i] == '0' && b[i] == '1')
		{
			if (carry)
			{
				carry = true;
				digit = "0";
			}
			else
				digit = "1";
		}
		else if (a[i] == '1' && b[i] == '0')
		{
			if (carry)
			{
				carry = true;
				digit = "0";
			}
			else
				digit = "1";
		}
		else if (a[i] == '1' && b[i] == '1')
		{
			if (carry)
				digit = "1";
			else
				digit = "0";

			carry = true;
		}

		result = digit + result;
	}

	if (carry)
		result = "1" + result;

	return result;
}
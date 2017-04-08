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
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
Show Company Tags
Show Tags
Show Similar Problems

*/

/*
"0"
"0"
"32423141234213421341243"
"32423141234213421341243"
*/



string multiply(string num1, string num2) {

	string result(num1.length() + num2.length(), '0');

	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int carry = 0;
		for (int j = num2.length() - 1; j >= 0; j--)
		{
			int tmp = (result[i + j - 1] - '0') + carry + ((num1[i] - '0') * (num2[j] - '0'));
			result[i + j - 1] = (tmp % 10) + '0';
			carry = tmp / 10;
		}
		result[i] += carry; // left over carry
	}

	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] != '0') return result.substr(i);
	}

	return "0";
}
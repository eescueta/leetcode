#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

/*
[0]
[1,2,9]
[9,9,9]
[9]
*/

vector<int> plusOne(vector<int>& digits) {
	int carry = 0;
	digits[digits.size() - 1]++;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		digits[i] += carry;
		if (digits[i] >= 10 && i > 0)
		{
			carry = 1;
			digits[i] = 0;
		}
		else if (digits[i] >= 10 && i == 0)
		{
			// create a new vector with result that is one length larger
			digits[0] = 0;
			vector<int> newResult;
			newResult.push_back(1);
			for (int j = 0; j < digits.size(); j++)
			{
				newResult.push_back(digits[j]);
			}
			return newResult;
		}
		else
		{
			carry = 0;
		}
	}

	return digits;
}
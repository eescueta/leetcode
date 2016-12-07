#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include "Solution.h"

using namespace std;

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
*/

/*
1
5
1
2
2
1
2
3
5
3
3
5
9
4
4
9
333
400
400
333
0
5
*/

string fractionToDecimal(int numerator, int denominator) {
	if (numerator == 0)
		return "0";
	if (numerator == denominator)
		return "1";
	
	string res = "";

	if (numerator < denominator)
	{
		res += "0.";
		numerator *= 10;
		
		string repeatingDecimal = "";
		while (numerator < denominator)
		{
			numerator *= 10;
			repeatingDecimal += to_string(0);
		}

		while (1)
		{
			int div = numerator / denominator;
			double div2 = (double)numerator / (double)denominator;
			if (div == div2)
			{
				res += repeatingDecimal;
				res += to_string(div);
				return res;
			}
			else
			{
				// place into res string
				if (repeatingDecimal == "")
				{
					repeatingDecimal += to_string(div);
				}
				else
				{
					char digit = div + '0';
					for (int i = 0; i < repeatingDecimal.length(); i++)
					{
						if (repeatingDecimal[i] == digit)
						{
							string nonRepeat = repeatingDecimal.substr(0, i);
							string repeat = repeatingDecimal.substr(i);
							return res + nonRepeat + "(" + repeat + ")";
						}
					}
					repeatingDecimal += digit;
				}

				int sub = denominator * div;
				numerator = numerator - sub;
				numerator *= 10;
			}
		}
	}
	else
	{
		int div = numerator / denominator;
		double div2 = (double)numerator / (double)denominator;
		if (div == div2)
		{
			return to_string(div);
		}
		else
		{
			res += to_string(div) + ".";
		}

		int sub = denominator * div;
		numerator = numerator - sub;
		numerator *= 10;
		string repeatingDecimal = "";

		while (1)
		{
			div = numerator / denominator;
			div2 = (double)numerator / (double)denominator;
			if (div == div2)
			{
				res += repeatingDecimal;
				res += to_string(div);
				return res;
			}
			else
			{
				char digit = div + '0';
				for (int i = 0; i < repeatingDecimal.length(); i++)
				{
					if (repeatingDecimal[i] == digit)
					{
						string nonRepeat = repeatingDecimal.substr(0, i);
						string repeat = repeatingDecimal.substr(i);
						return res + nonRepeat + "(" + repeat + ")";
					}
				}
				repeatingDecimal += digit;
			}

			sub = denominator * div;
			numerator = numerator - sub;
			numerator *= 10;
		}
	}



	return res;
}
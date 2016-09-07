#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
*/

/*
1
2
3
4
5
6
*/

string countAndSay(int n) {
	if (n <= 1)
		return "1";

	string lastResult = countAndSay(n - 1);
	string currResult = "";

	char currentChar = lastResult[0];
	int currentCount = 1;

	for (int i = 1; i < lastResult.length(); i++)
	{
		if (lastResult[i] != currentChar)
		{
			currResult = currResult + to_string(currentCount) + currentChar;
			currentChar = lastResult[i];
			currentCount = 1;
		}
		else
			currentCount++;
	}

	if (currentCount > 0)
	{
		currResult = currResult + to_string(currentCount) + currentChar;
	}


	return currResult;
}
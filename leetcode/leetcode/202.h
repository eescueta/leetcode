#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

/*
0
1
19
101
56
123456
5
9
56
987
456
1233264
*/

int sumSquareDigits(int n)
{
	int sum = 0;

	while (n > 0)
	{
		int lastDigit = n % 10;
		sum += (lastDigit * lastDigit);
		n /= 10;
	}

	return sum;
}

bool isHappy(int n) {

	int startingVal = n;
	map<int, bool> archive;
	archive[n] = true;

	int sSD = sumSquareDigits(n);
	while (sSD != 0)
	{
		if (!archive[sSD])
		{
			archive[sSD] = true;
			sSD = sumSquareDigits(sSD);
		}
		else
			return false;
	}

	return true;

}


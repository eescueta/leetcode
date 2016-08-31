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
263. Ugly Number  QuestionEditorial Solution  My Submissions
Total Accepted: 72201
Total Submissions: 190994
Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

/*
Your input
-2147483648
0
1
10
15
-15
49
-49
14
*/

bool isUgly(int num) {
	if (num <= 0)
		return false;
	
	if (num == 1)
		return true;

	while (num != 1)
	{
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else
			return false;
	}
	return true;
}
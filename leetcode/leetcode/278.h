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
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersionHelper(int start, int end)
	{
		if (isBadVersion(start))
			return start;

		if (start == end)
			return start;

		int mid = start-1 + ( ((end+1) - (start-1)) / 2);

		if (start == mid)
			return firstBadVersionHelper(start + 1, mid);

		if (isBadVersion(mid) && !isBadVersion(mid - 1))
			return mid;
		else if (isBadVersion(mid))
		{
			return firstBadVersionHelper(start, mid);
		}
		else
		{
			return firstBadVersionHelper(mid, end);
		}

	}

	int firstBadVersion(int n) {
		return firstBadVersionHelper(1, n);
	}
};
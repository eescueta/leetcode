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
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB
*/

/*
1
26
676
58
702
18252
18278
123456
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

		int mid = start - 1 + (((end + 1) - (start - 1)) / 2);

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
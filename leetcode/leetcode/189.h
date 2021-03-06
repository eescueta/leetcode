#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include "Solution.h"

using namespace std;

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

/*
[1]
0
[1,2,3,4,5,6,7]
3
[1,2,3,4,5,6]
11
[1,2]
1
[1,2,3,4,5,6]
2
*/


void rotate(vector<int>& nums, int k) {
	if (k <= 0)
		return;

	while (k > nums.size())
		k -= nums.size();

	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

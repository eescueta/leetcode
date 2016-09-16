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
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

/*
3
7
3
9
*/

void combinationSum3Helper(int k, int n, int currentNumber ,vector<int> currentArray, vector<vector<int>>* results)
{
	if (currentArray.size() == 3 && n == 0)
	{
		(*results).push_back(currentArray);
			return;
	}
	else if (currentArray.size() > 3 || n < 0)
		return;
	else {
		for (int i = currentNumber + 1; i <= 9; i++)
		{
			vector<int> v = currentArray;
			v.push_back(i);
			combinationSum3Helper(k, n - i, i, v, results);
		}
	}

}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> results;

	for (int i = 1; i <= 9; i++)
	{
		combinationSum3Helper(k, n-i, i, { i }, &results);
	}

	return results;
}
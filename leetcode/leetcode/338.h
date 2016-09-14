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
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Hint:

You should make use of what you have produced already.
*/

/*
0
1
2
3
4
5
6
7
8
*/

vector<int> countBits(int num) {
	vector<int> results = { 0 };
	// stop when results size is num + 1
	while (results.size() < num + 1)
	{
		vector<int> newSetOfBits;
		// calculate new # of bits or new numbers
		for (int i = 0; i < results.size(); i++)
		{
			newSetOfBits.push_back(results[i] + 1);
		}

		//push new set to results
		for (int i = 0; i < newSetOfBits.size(); i++)
		{
			results.push_back(newSetOfBits[i]);
			if (results.size() == num + 1)
				break;
		}
	}

	return results;
}
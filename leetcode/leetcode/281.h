#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/

/*
[1,2]
[3,4,5,6]
[]
[3,4,5,6]
[1,2]
[]
[1,2,3]
[4,5,6]
[]
[]
*/

class ZigzagIterator {
public:
	vector<vector<int>> vectors;
	int it = 0; // element iterator
	int VecIt = 0; // vector iterator

	int maxIndex = 0; // last index of biggest vector


	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		vectors.push_back(v1);
		vectors.push_back(v2);
		maxIndex = INT_MIN;
		it = 0;
		VecIt = 0;

		for (int i = 0; i < vectors.size(); i++)
		{
			int wtf = vectors[i].size() - 1;
			if (wtf > maxIndex)
				maxIndex = wtf;
		}
	}

	int next() {
		if (!hasNext())
			return -1;

		// check for current vector too small
		int wtf = vectors[VecIt].size() - 1;
		while (it > wtf && it <= maxIndex)
		{
			VecIt++;

			// reset current vector to first vector
			if (VecIt >= vectors.size())
			{
				VecIt = 0;
				it++;
			}

			wtf = vectors[VecIt].size() - 1;
		}

		int res = vectors[VecIt][it];

		// reset current vector to first vector
		VecIt++;
		if (VecIt >= vectors.size())
		{
			VecIt = 0;
			it++;
		}

		// check for current vector too small
		wtf = vectors[VecIt].size() - 1;
		while (it > wtf && it <= maxIndex)
		{
			VecIt++;

			// reset current vector to first vector
			if (VecIt >= vectors.size())
			{
				VecIt = 0;
				it++;
			}

			wtf = vectors[VecIt].size() - 1;
		}

		return res;
	}

	bool hasNext() {
		if (it > maxIndex)
			return false;
		else
			return true;
	}
};
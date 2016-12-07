#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include "Solution.h"

using namespace std;

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Show Company Tags
Hide Tags
*/

/*
[0]
[100, 4, 200, 1, 3, 2]
[100, 4, 104, 200, 1, 101, 3, 102, 2, 103]
[]
*/

int longestConsecutive(vector<int>& nums) {
	if (nums.size() == 0)
		return 1;

	map<int, int> ranges;

	int maxRange = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// dupes
		if (ranges.count(nums[i]) > 0)
			continue;

		int left = ranges.count(nums[i]-1) ? ranges[nums[i]-1] : 0;
		int right = ranges.count(nums[i] + 1) ? ranges[nums[i] + 1] : 0;

		int r = left + 1 + right;
		ranges[nums[i]] = r;

		if (r != 1)
		{
			ranges[nums[i] - left] = r;
			ranges[nums[i] + right] = r;
		}

		maxRange = max(maxRange, r);
	}

	return maxRange;
}


//int longestConsecutive(vector<int>& nums) {
//	vector<list<int>> sequences = {};
//
//	if (nums.size() == 0 || nums.size() == 1)
//		return 1;
//
//	list<int> firstSequence = {};
//	firstSequence.push_back(nums[0]);
//	sequences.push_back(firstSequence);
//
//	int maxSequence = 1;
//
//	for (int i = 1; i < nums.size(); i++)
//	{
//		for (int j = 0; j < sequences.size(); j++)
//		{
//			bool isInSequence = false;
//			// insert num into beginning of a sequnce
//			if (sequences[j].front() == nums[i] + 1)
//			{
//				sequences[j].push_front(nums[i]);
//				isInSequence = true;
//			}
//			// insert num into end of a sequence
//			if (sequences[j].back() == nums[i] - 1)
//			{
//				sequences[j].push_back(nums[i]);
//				isInSequence = true;
//			}
//
//			if (isInSequence && sequences[j].size() > maxSequence)
//				maxSequence = sequences[j].size();
//		}
//
//		// when num wasnt inserted into any sequence
//		list<int> newSeq = { nums[i] };
//		sequences.push_back(newSeq);
//	}
//
//	return maxSequence;
//}
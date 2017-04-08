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
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

/*
[]
[5,7]
[[1,3],[6,9]]
[2,5]
[[1,2],[3,5],[6,7],[8,10],[12,16]]
[4,9]
*/



bool static sortInterval(Interval A, Interval B)
{
	return A.start < B.start;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

	intervals.push_back(newInterval);
	sort(intervals.begin(), intervals.end(), sortInterval);

	vector<Interval> result = { intervals[0] };

	for (int i = 1; i < intervals.size(); i++)
	{
		// curr interval is separate
		if (intervals[i].start > result.back().end)
			result.push_back(intervals[i]);
		// curr interval extends last interval
		// curr interval is "swallowed" by the last interval
		else if (intervals[i].start <= result.back().end)
			result.back().end = max(result.back().end, intervals[i].end);
	}

	return result;
}
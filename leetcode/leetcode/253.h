#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

/*
0
2017
12
5872
*/

static bool sortInterval(Interval a, Interval b)
{
	return a.start < b.start;
}

int minMeetingRooms(vector<Interval>& intervals) {
	if (intervals.size() == 0) return 0;
	sort(intervals.begin(), intervals.end(), sortInterval);

	vector<vector<Interval>> roomSchedule = {  };

	for (int i = 0; i < intervals.size(); i++)
	{
		bool foundRoom = false;
		for (int j = 0; j < roomSchedule.size(); j++)
		{
			if (intervals[i].start >= roomSchedule[j].back().end)
			{
				roomSchedule[j].push_back(intervals[i]);
				foundRoom = true;
				break; // forgot to break
			}
		}

		if (!foundRoom)
		{
			roomSchedule.push_back({ intervals[i] });
		}
	}
	
	return roomSchedule.size();
}
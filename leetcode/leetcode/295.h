#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include "Solution.h"

using namespace std;

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/


class MedianFinder {
public:

	priority_queue<int> lower_half;
	priority_queue<int> upper_half;

	// Adds a number into the data structure.
	void addNum(int num) {
		lower_half.push(num);
		int i = lower_half.top();
		lower_half.pop();
		upper_half.push(-i);

		if (upper_half.size() > lower_half.size())
		{
			lower_half.push(-upper_half.top());
			upper_half.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (upper_half.size() == lower_half.size())
		{
			return ((double)(-upper_half.top()) + (double)(lower_half.top())) / 2;
		}
		else
			return lower_half.top();
	}
};
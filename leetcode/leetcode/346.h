#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
	/** Initialize your data structure here. */
	int capacity;
	queue<int> q;
	double currAvg;
	MovingAverage(int size) {
		capacity = size;
	}

	double next(int val) {
		if (q.size() == 0)
		{
			q.push(val);
			currAvg = (double)val;
			return val;
		}
		else if (q.size() < capacity)
		{
			currAvg *= q.size();
			q.push(val);
			currAvg += val;
			currAvg /= q.size();
			return currAvg;
		}
		else
		{
			currAvg *= q.size();
			currAvg -= q.front();
			q.pop();
			q.push(val);
			currAvg += val;
			currAvg /= q.size();
			return currAvg;
		}
	}
};
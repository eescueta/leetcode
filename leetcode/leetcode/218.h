#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include "Solution.h"

using namespace std;

/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

/*
[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
[[0,2,3],[2,5,3]]
*/

struct skylinePoint
{
	int x;
	int height;
	bool isEnd;
};

bool static skylineSort(skylinePoint A, skylinePoint B)
{
	if (A.x < B.x)
		return true;
	if (A.x > B.x)
		return false;

	if (A.isEnd != B.isEnd)
		return !A.isEnd;

	if (A.isEnd)
	{
		return A.height < B.height;
	}
	else
	{
		return A.height > B.height;
	}


}


vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	vector<skylinePoint> points;

	for (int i = 0; i < buildings.size(); i++)
	{
		skylinePoint currBegin;
		skylinePoint currEnd;
		currBegin.x = buildings[i][0];
		currEnd.x = buildings[i][1];
		currBegin.height = currEnd.height = buildings[i][2];
		currBegin.isEnd = false;
		currEnd.isEnd = true;
		points.push_back(currBegin);
		points.push_back(currEnd);
	}

	sort(points.begin(), points.end(), skylineSort);

	//// pair testing
	//for (int i = 0; i < points.size(); i++)
	//{
	//	cout << points[i].x << " " << points[i].height << " " << points[i].isEnd << endl;
	//}

	multiset<int> maxHeightTracker;
	maxHeightTracker.insert(0);
	vector<pair<int, int>> results;

	for (int i = 0; i < points.size(); i++)
	{

		int currMaxHeight = *maxHeightTracker.rbegin();
		if (!points[i].isEnd)
		{
			maxHeightTracker.insert(points[i].height); 
			if (points[i].height > currMaxHeight)
			{
				pair<int, int> p;
				p.first = points[i].x;
				p.second = points[i].height;
				results.push_back(p);
			}
		}
		else
		{
			auto itr = maxHeightTracker.find(points[i].height);
			if (itr != maxHeightTracker.end())
				maxHeightTracker.erase(itr);

			if (*maxHeightTracker.rbegin() != currMaxHeight)
			{
				pair<int, int> p;
				p.first = points[i].x;
				p.second = *maxHeightTracker.rbegin();
				results.push_back(p);
			}
		}
	}

	return results;
}
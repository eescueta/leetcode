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
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*

*/

void solveTowers(vector<stack<int>>& towers, int size, int src, int dest)
{
	if (src < 0 || src > 2 || dest < 0 || dest > 2) return;

	if (size == 1)
	{
		if (towers[dest].size() > 0 && towers[dest].top() < towers[src].top())
			throw std::invalid_argument("Cannot place bigger number on top of smaller one");

		int i = towers[src].top();
		towers[src].pop();
		towers[dest].push(i);
		return;
	}

	//get other tower
	int otherTower;
	for (int i = 0; i < 3; i++)
	{
		if (i != src && i != dest)
			otherTower = i;
	}

	solveTowers(towers, size - 1, src, otherTower);
	solveTowers(towers, 1, src, dest);
	solveTowers(towers, size - 1, otherTower, dest);

	return;
}

vector<stack<int>> towerOfHanoi(int n)
{
	vector<stack<int>> towers(3);
	for (int i = n; i > 0; i--)
	{
		towers[0].push(i);
	}

	solveTowers(towers, n, 0, 2);

	return towers;
}
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
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/


// dummy
bool knows(int a, int b)
{
	return true;
}

int findCelebrity(int n) {
	if (n == 0) return false;
	
	vector<int> candidates(n, false);
	candidates[0] = true;
	// zero row
	for (int k = 1; k < n; k++)
	{
		if (knows(0, k))
		{
			candidates[k] = true;
			candidates[0] = false;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i == k)
				continue;

			if (candidates[k] != false)
				candidates[k] = knows(i, k);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (candidates[i])
		{
			bool isCeleb = true;
			for (int j = 0; j < n; j++)
			{
				if (j == i) continue;
				if (knows(i, j))
					isCeleb = false;
			}

			if (isCeleb) return i;
		}
	}

	return -1;
}
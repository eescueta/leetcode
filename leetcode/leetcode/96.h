#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"

using namespace std;

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
0
1
2
3
4
5
*/

int numTreesHelper(int n, map<int, int>* solutionArchive)
{
	if ((*solutionArchive).count(n) > 0)
		return (*solutionArchive)[n];

	int ctr1 = 0;
	int ctr2 = n - 1;

	int result = 0;

	while (ctr1 < n)
	{
		if (ctr1 == 0)
			result += numTreesHelper(ctr2, solutionArchive);
		else if (ctr2 == 0)
			result += numTreesHelper(ctr1, solutionArchive);
		else
			result += numTreesHelper(ctr1, solutionArchive) * numTreesHelper(ctr2, solutionArchive);

		ctr1++;
		ctr2--;
	}

	(*solutionArchive)[n] = result;
	return result;
}

int numTrees(int n) {
	map<int, int> solutionArchive;
	solutionArchive[0] = 0;
	solutionArchive[1] = 1;

	return numTreesHelper(n, &solutionArchive);
}
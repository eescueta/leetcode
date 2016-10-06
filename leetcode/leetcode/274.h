#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include "Solution.h"

using namespace std;

/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
Credits:
*/


/*
[]
[1,1,2,2,3,3]
[3, 0, 6, 1, 5]
[10, 8, 5, 4, 3]
[1]
[1,1,1,1,0]
[1,0,0,0,0]
[10,9,8,7]
[10,9]
[10]
[10,9,8]
[10,9,8,7,6]
[0]
[0,1,1,1]
[1,2]
[10]
[9]
*/


int hIndex(vector<int>& citations) {
	if (citations.size() == 0)
		return 0;

	sort(citations.begin(), citations.end());
	reverse(citations.begin(), citations.end());

	if (citations[0] == 0)
		return 0;

	if (citations.size() == 1 || citations[0] == 1)
		return 1;

	int b = 0;

	for (int i = 1; i < citations.size(); i++)
	{
		int a = min(citations[i], i + 1);
		if (a > b)
			b = a;
	}

	return b;
}
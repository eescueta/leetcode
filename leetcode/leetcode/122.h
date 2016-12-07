#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include "Solution.h"

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share
of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
[]
[1]
[2,6,4,8,3,5]
[4,2,2,4,4]
[2,1,3,3,4]
*/

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	
	int min = 0;
	int max = 0;
	int profit = 0;
	//bool minSet = false;

	for (int i = 0; i < prices.size(); i++)
	{
		if (i == 0)
		{
			if (prices[0] < prices[1])
				min = prices[0];

			continue;
		}

		if (i == prices.size() - 1)
		{
			if (prices[i] > prices[i - 1])
				profit += prices[i] - min;

			continue;
		}

		//min
		if (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1])
			min = prices[i];

		if (prices[i] > prices[i - 1] && prices[i] >= prices[i + 1])
			profit += prices[i] - min;
	}

	return profit;

}
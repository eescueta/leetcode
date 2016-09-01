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
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

/*
[7, 1, 5, 3, 6, 4]
[7, 6, 4, 3, 1]
[7, 6, 4, 3, 1, 2]
*/


int maxProfit(vector<int>& prices) {
	int buy_price = INT_MAX;
	int profit = 0;

	if (prices.size() <= 1)
		return 0;

	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (prices[i] < buy_price)
		{
			buy_price = prices[i];

			for (int j = i + 1; j < prices.size(); j++)
			{
				if (prices[j] - buy_price > profit)
					profit = prices[j] - buy_price;
			}
		}
	}

	return profit;
}
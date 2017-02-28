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
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

/*
[1]
0
[1,2,5]
11
[2]
3
[1]
1
[5,3,2]
16
[186,419,83,408]
6249
*/


// iterative
int coinChange(vector<int>& coins, int amount) {
	vector<int> leastCoinsRequired(amount + 1, INT_MAX);
	leastCoinsRequired[0] = 0;

	// solve for amount = 1, 2, 3, ... amount
	for (int i = 1; i <= amount; i++)
	{
		int answer = -1;
		for (int j = 0; j < coins.size(); j++)
		{
			if (coins[j] <= i)
			{
				int lastAnswer = leastCoinsRequired[i - coins[j]];
				if (lastAnswer != -1)
				{
					if (answer == -1)
						answer = lastAnswer+1;
					else
						answer = min(answer, lastAnswer + 1);
				}
			}
		}
		leastCoinsRequired[i] = answer;
	}

	return leastCoinsRequired[amount];
}

// memoize
int coinChangeHelper(vector<int>& coins, int amount, map<int, int>& changeArchive)
{
	if (amount < 0) return -1;
	if (amount == 0) return 0;
	if (changeArchive[amount] != 0) return changeArchive[amount];

	int ways = coinChangeHelper(coins, amount - coins[coins.size() - 1], changeArchive);
	for (int i = coins.size() - 2; i >= 0; i--)
	{
		int ccH = coinChangeHelper(coins, amount - coins[i], changeArchive);
		if (ways == -1)
			ways = ccH;
		else if (ccH != -1)
			ways = min(ways, ccH);
	}

	if (ways < 0)
	{	
		changeArchive[amount] = ways;
		return ways;
	}

	changeArchive[amount] = ways+1;
	return ways+1;
}

int coinChangeOld(vector<int>& coins, int amount) {
	map<int, int> changeArchive;
	return coinChangeHelper(coins, amount, changeArchive);
}
#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include "Solution.h"
#include <cstdint>

using namespace std;

/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
1 : My number is higher
0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/

/*
10
6
11
5
11
6
11
7

*/

// guess number over a range
int guessNumberHelper(int min, int max) {
	int g = min + ((max - min) / 2);

	if (max - min == 1 && guess(max) == 0)
	{
		return max;
	}

	if (guess(g) == 0)
		return g;
	else if (guess(g) == -1)
		return guessNumberHelper(min, g);
	else if (guess(g) == 1)
		return guessNumberHelper(g, max);

	// neva neva reach this
	return 0;
}

int guessNumber(int n) {
	return  guessNumberHelper(1, n);
}

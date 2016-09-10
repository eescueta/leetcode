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
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

/*
*/


uint32_t reverseBits(uint32_t n) {
	int result = 0;

	for (int i = 0; i <= 31; i++)
	{
		int lsb = n & 1;
		n = n >> 1;
		result += lsb;
		if (i != 31)
		{
			result = result << 1;
		}
	}

	return result;
}
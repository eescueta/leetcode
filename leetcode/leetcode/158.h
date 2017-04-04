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
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

*/


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	/**
	* @param buf Destination buffer
	* @param n   Maximum number of characters to read
	* @return    The number of characters read
	*/
	char* leftovers = new char[3];
	int num_leftovers = 0;
	int leftover_index = 0;
	int read(char *buf, int n) {
		int total_written = 0;


		// get leftovers first
		for (int i = leftover_index; i < num_leftovers && total_written < n; i++)
		{
				buf[total_written] = leftovers[i];
				total_written++;
				leftover_index++;
		}

		if (total_written == n) return total_written;
		num_leftovers = 0;
		leftover_index = 0;
		char* tmp = new char[4];

		//do normally but save leftovers
		while (total_written < n)
		{
			int num_read = read4(tmp);

			if (num_read == 0) break;

			for (int i = 0; i < num_read; i++)
			{
				if (total_written < n)
				{
					buf[total_written] = tmp[i];
					total_written++;
				}
				else
				{
					leftovers[num_leftovers] = tmp[i];
					num_leftovers++;
				}
			}
		}

		return total_written;
	}
};
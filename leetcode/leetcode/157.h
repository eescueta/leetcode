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
The read function will only be called once for each test case.
*/


int read4(char *buf);

int read(char *buf, int n) {
	char[] tmp = new char[4];
	int total_read = 0;

	while (total_read < n)
	{
		int num_read = read4(tmp);

		if (num_read == 0) break;

		for (int i = 0; i < num_read; i++)
		{
			buf[total_read] = tmp[i];
			total_read++;
			if (total_read == n)
				break;
		}

	}

	return total_read;
}
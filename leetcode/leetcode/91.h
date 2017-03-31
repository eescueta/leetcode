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
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

/*
"17893"
"2"
"17893"
"21"
"7893"
"217893"
"2017"
"0"
"5827"
"12"
"2173"
"2323732"
"2"
"323732"
"23732"
*/


int numDecodings(string s) {
	if (s == "" || s[0] == '0') return 0;

	vector<int> answers(s.length() + 1);
	answers.back() = 1;

	if (s.back() != '0')
		answers[answers.size() - 2] = 1;

	for (int i = s.size() - 2; i >= 0; i--)
	{
		if (s[i] != '0')
			answers[i] += answers[i + 1];

		if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
			answers[i] += answers[i + 2];
	}

	return answers[0];
}

map<string, int> decodeArchive;

int numDecodingsOld(string s) {
	if (s == "") return 0;

	int res = 0;

	char first = s[0];
	if (first == '0') return 0;
	if (s.length() == 1) return 1;

	if (decodeArchive.find(s) != decodeArchive.end())
	{
		return decodeArchive[s];
	}

	res += numDecodingsOld(s.substr(1));

	char second = s[1];
	if ((first == '1') || (first == '2' && second >= '0' && second <= '6'))
	{
		// messed up this part
		if (s.length() == 2)
			res++;
		else
			res += numDecodings(s.substr(2));
	}

	decodeArchive[s] = res;
	return res;


}
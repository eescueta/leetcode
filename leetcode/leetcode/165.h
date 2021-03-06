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
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

/*
"1"
"0"
"1.1"
"1.11"
"2.1"
"1.5"
"1.2999"
"1.3"
"1.2999"
"1.3000"
"1.11"
"1.11"
"01"
"1"
"1"
"1.1"
"1.1"
"1"
"1.0.1"
"1"
*/

int compareVersion(string version1, string version2) {
	// parse version1
	vector<string> V1;
	int i = 0;
	string currLevel = "";
	while (i < version1.length())
	{
		if (version1[i] == '.')
		{
			if (currLevel != "")
				V1.push_back(currLevel);
			else
				V1.push_back("0");

			currLevel = "";
		}
		else
		{
			currLevel += version1[i];
		}
		i++;
	}

	if (currLevel != "")
		V1.push_back(currLevel);
	else
		V1.push_back("0");

	// parse version2
	vector<string> V2;
	i = 0;
	currLevel = "";
	while (i < version2.length())
	{
		if (version2[i] == '.')
		{
			if (currLevel != "")
				V2.push_back(currLevel);
			else
				V2.push_back("0");

			currLevel = "";
		}
		else
		{
			currLevel += version2[i];
		}
		i++;
	}
	if (currLevel != "")
		V2.push_back(currLevel);
	else
		V2.push_back("0");

	// compare both version level arrays
	int compareLength = max(V1.size(), V2.size());

	for (int i = 0; i < compareLength; i++)
	{
		int ver1Num;
		int ver2Num;

		if (i >= V1.size())
			ver1Num = 0;
		else
			ver1Num = stoi(V1[i]);
		if (i >= V2.size())
			ver2Num = 0;
		else
			ver2Num = stoi(V2[i]);

		if (ver1Num > ver2Num)
			return 1;
		else if (ver2Num > ver1Num)
			return -1;
	}

	return 0;


}


int compareVersionWrong(string version1, string version2) {
	// parse version 1
	string V1L1 = "";
	string V1L2 = "";
	int i = 0;
	while (i < version1.length() && version1[i] != '.')
	{
		V1L1 += version1[i];
		i++;
	}
	i++;
	while (i < version1.length())
	{
		V1L2 += version1[i];
		i++;
	}

	// parse version2
	string V2L1 = "";
	string V2L2 = "";
	int j = 0;
	while (j < version2.length() && version2[j] != '.')
	{
		V2L1 += version2[j];
		j++;
	}
	j++;
	while (j < version2.length())
	{
		V2L2 += version2[j];
		j++;
	}

	if (stoi(V1L1) > stoi(V2L1))
		return 1;
	else if (stoi(V1L1) < stoi(V2L1))
		return -1;

	if (V1L2 == "" && V2L2 == "")
		return 0;
	else if (V1L2 == "")
		V1L2 = "0";
	else if (V2L2 == "")
		V2L2 = "0";

	// check second level
	if (stoi(V1L2) > stoi(V2L2))
		return 1;
	else if (stoi(V1L2) < stoi(V2L2))
		return -1;

	return 0;
}
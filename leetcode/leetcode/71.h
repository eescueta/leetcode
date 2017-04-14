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
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*
"/"
"/home/"
"/../"
"/a/./b/../../c/"
"/home//foo/"
"/..."
"/."
"/.."
"/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///"
*/


string simplifyPath(string path)
{
	stack<string> folderNames;
	int leftIt = 0; // '/'

	for (int rightIt = 1; rightIt < path.size(); rightIt++)
	{
		if (path[rightIt] == '/')
		{
			string folderName = path.substr(leftIt + 1, rightIt - leftIt - 1);

			leftIt = rightIt;
			if (folderName == "." || folderName == "")
				continue;
			else if (folderName == "..")
			{
				if (!folderNames.empty())
					folderNames.pop();
			}
			else
				folderNames.push(folderName);
		}
	}

	// get last folder if input does not end with '/'
	if (path.back() != '/' && leftIt < path.length())
	{
		string lastFolder = path.substr(leftIt + 1);
		if (lastFolder == "..")
		{
			if (!folderNames.empty())
				folderNames.pop();
		}
		else if (lastFolder == "." || lastFolder == "")
		{
			// do nothing
		}
		else
			folderNames.push(lastFolder);
	}	

	if (folderNames.empty())
		return "/";

	// write string

	string result = "";
	while (!folderNames.empty())
	{
		result = "/" + folderNames.top() + result;
		folderNames.pop();
	}
	return result;
}



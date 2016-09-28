#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <sstream>
#include "Solution.h"

using namespace std;

/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/


/*
"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
"dir\n\taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
"dir\n\ta\n\t\ta\n\t\t\ta.txt\n\taaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.txt"
"dir\n    file.txt"
*/

struct link
{
	string name;
	bool file;
	vector<link> subLinks;
	int level;
};

int lengthLongestPathHelper(link l)
{
	if (l.file)
		return l.name.length();
	else
	{
		int max = 0;
		for (int i = 0; i < l.subLinks.size(); i++)
		{
			int res = lengthLongestPathHelper(l.subLinks[i]);
			if (res > max)
				max = res;
		}

		// name + / + recursive result
		return l.name.length() + 1 + max;
	}
}


int lengthLongestPath(string input) {
	vector<string> names; // all file names and folder names
	
	// split the string with newline
	istringstream f(input);
	string s;
	while (getline(f, s, '\n'))
	{
		names.push_back(s);
	}

	stack<link> hierarchy;

	for (int i = 0; i < names.size(); i++)
	{
		// get level
		int level = 0;
		while (names[i][level] == '\t' && level < names[i].length())
		{
			level++;
		}

		// get whether or not is a file
		bool f = false;
		for (int j = names[i].length() - 1; j >= 0; j--)
		{
			if (names[i][j] == '.')
			{
				f = true;
				break;
			}
		}

		string filename = names[i].substr(level);

		link l;
		l.name = filename;
		l.file = f;
		l.level = level;

		if (hierarchy.size() == 0)
		{
			hierarchy.push(l);
		}
		else if (hierarchy.top().level < l.level)
		{
			//hierarchy.top().subLinks.push_back(l);
			hierarchy.push(l);
		}
		else 
		{
			while (hierarchy.top().level >= l.level)
			{
				link oldTop = hierarchy.top();
				hierarchy.pop();

				if (oldTop.file || oldTop.subLinks.size() > 0)
					hierarchy.top().subLinks.push_back(oldTop);
			}

			//hierarchy.top().subLinks.push_back(l);
			hierarchy.push(l);
		}
	}

	// resolve hierarchy by emptying the stack except for root directory
	while (hierarchy.size() > 1)
	{
		link oldTop = hierarchy.top();
		hierarchy.pop();

		if (oldTop.file || oldTop.subLinks.size() > 0)
			hierarchy.top().subLinks.push_back(oldTop);
	}

	return lengthLongestPathHelper(hierarchy.top());
}
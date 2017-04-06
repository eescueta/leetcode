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
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

Show Company Tags
Hide Tags
*/

/*
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
*/


/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation

*/

class NestedInteger {
	public:
		     // Return true if this NestedInteger holds a single integer, rather than a nested list.
			     bool isInteger() const;
		
			    // Return the single integer that this NestedInteger holds, if it holds a single integer
			     // The result is undefined if this NestedInteger holds a nested list
			     int getInteger() const;
		
			     // Return the nested list that this NestedInteger holds, if it holds a nested list
			     // The result is undefined if this NestedInteger holds a single integer
			    const vector<NestedInteger> &getList() const;
		
};


class NestedIterator {
public:


	stack<vector<NestedInteger>> elementStack;
	stack<int> indexStack;

	NestedIterator(vector<NestedInteger> &nestedList) {


		elementStack.push(nestedList);

		NestedInteger currElement = nestedList[0];
		indexStack.push(0);


		while (!currElement.isInteger())
		{
			elementStack.push(currElement.getList());
			indexStack.push(0);
			currElement = elementStack.top()[0];
		}
	}

	int next() {
		vector<NestedInteger> currArr = elementStack.top();
		int currIndex = indexStack.top();

		int retVal = currArr[indexStack.top()].getInteger();
		cout << "test" << endl;
		indexStack.top()++;

		while (indexStack.top() >= currArr.size())
		{
			elementStack.pop();
			if (elementStack.empty()) return retVal;
			currArr = elementStack.top();
			indexStack.pop();
			currIndex = indexStack.top();
			indexStack.top()++;
		}

		NestedInteger currElem = currArr[indexStack.top()];

		while (!currElem.isInteger())
		{
			elementStack.push(currElem.getList());
			indexStack.push(0);
			currElem = elementStack.top()[0];
		}

		cout << retVal << endl;
		return retVal;
	}

	bool hasNext() {
		return elementStack.size() > 0;
	}
};
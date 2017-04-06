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
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
Show Company Tags
Hide Tags
*/

/*
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
*/


class WordDictionary {
public:
	struct TrieNode
	{
		char val;
		vector<TrieNode*> children;
		bool isEnd;

		TrieNode(char c)
		{
			val = c;
			vector<TrieNode*> v(26, NULL);
			children = v;
			isEnd = false;
		}

	};

	TrieNode* root;

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode('\0');
		root->isEnd = true;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (curr->children[word[i] - 'a'] == NULL)
				curr->children[word[i] - 'a'] = new TrieNode(word[i]);

			curr = curr->children[word[i] - 'a'];
		}

		curr->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool searchHelper(string word, TrieNode* curr, int idx)
	{
		if (curr == NULL) return false;
		if (idx == word.length())
			return curr->isEnd;


		char currChar = word[idx];

		if (currChar == '.')
		{
			for (int i = 0; i < 26; i++)
			{
				if (curr->children[i] != NULL)
					if (searchHelper(word, curr->children[i], idx + 1))
						return true;
			}
			return false;
		}

		return curr->children[word[idx] - 'a'] != NULL && searchHelper(word, curr->children[word[idx] - 'a'], idx + 1);
	}

	bool search(string word) {
		return searchHelper(word, root, 0);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/
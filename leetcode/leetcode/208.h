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
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

/*
["Trie","search"]
[[],["a"]]
["Trie","search"]
[[],["a"]]
["Trie","insert","search","startsWith","search","search","startsWith","search"]
[[],["earl"],["earl"],["ear"],["eral"],["asfgbdfaafsa"],["era"],["ear"]]
*/

class Trie {
private:
	struct TrieNode {
		char val;
		bool isEnd; //marks whether or not this node is an end of a word
		vector<TrieNode*> children;
		TrieNode(char v)
		{
			val = v;
			vector<TrieNode*> c(26, NULL);
			children = c;
			isEnd = false;
		}
	};

	TrieNode* root;
public:
	/** Initialize your data structure here. */
	

	Trie() {
		root = new TrieNode(' ');
		root->isEnd = true;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (curr->children[word[i] - 'a'] == NULL)
				curr->children[word[i] - 'a'] = new TrieNode(word[i]);
			
			curr = curr->children[word[i] - 'a'];
		}

		curr->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (curr->children[word[i] - 'a'] == NULL)
				return false;

			curr = curr->children[word[i] - 'a'];
		}

		return (curr->isEnd);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* curr = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (curr->children[word[i] - 'a'] == NULL)
				return false;

			curr = curr->children[word[i] - 'a'];
		}

		return (curr != NULL);
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/
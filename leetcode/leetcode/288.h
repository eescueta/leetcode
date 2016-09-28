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
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

class ValidWordAbbr {
public:
	map<string, vector<string>> abbDictionary;

	string getAbbrv(string s)
	{
		if (s.length() <= 2)
			return s;

		return s[0] + to_string(s.length() - 2) + s[s.length() - 1];
	}

	ValidWordAbbr(vector<string> &dictionary) {
		for (int i = 0; i < dictionary.size(); i++)
		{
			string abb = getAbbrv(dictionary[i]);

			// check if word already archived
			bool contains = false;
			for (int j = 0; j < abbDictionary[abb].size(); j++)
			{
				if (abbDictionary[abb][j] == dictionary[i])
					contains = true;
			}

			if (!contains)
				abbDictionary[abb].push_back(dictionary[i]);
		}
	}

	bool isUnique(string word) {
		string abb = getAbbrv(word);

		if (abbDictionary.count(abb))
		{
			if (abbDictionary[abb].size() == 1 && abbDictionary[abb][0] == word)
				return true;
			else
				return false;
		}
		else
			return true;
	}
};

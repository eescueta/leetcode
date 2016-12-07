#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include "Solution.h"

using namespace std;

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache {
public:
	int cap;
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (cache.count(key) <= 0)
			return -1;

		int res = cache[key].first;

		//update lru
		lru.erase(cache[key].second);
		lru.push_front(key);
		cache[key].second = lru.begin();

		return res;
	}

	void set(int key, int value) {
		//erase old key, val if it exists
		if (cache.count(key) > 0)
		{
			lru.erase(cache[key].second);
			cache.erase(key);
		}


		// insert new key,val
		lru.push_front(key);
		pair<int, list<int>::iterator > p;
		p.first = value;
		p.second = lru.begin();
		cache[key] = p;

		// get rid of lru
		if (lru.size() > cap)
		{
			cache.erase(lru.back());
			list<int>::iterator lruEnd = lru.end();
			lruEnd--;
			lru.erase(lruEnd);
		}
	}

	list<int> lru; // keeps track of used order by key;
	map<int, pair<int, list<int>::iterator> > cache;
};
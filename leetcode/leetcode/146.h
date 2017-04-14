#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
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

/*
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
["LRUCache","put","put","put","put","get","get"]
[[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
*/

class LRUCache {
private:
	list<int> lru; // holds keys, lru is at front
	unordered_map<int, pair<int, list<int>::iterator>> cache; // key to (value, iterator to lru list)
	int cap;
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (cache.find(key) == cache.end())
			return -1;

		// get value
		int result = cache[key].first;

		// update lru
		lru.erase(cache[key].second);
		lru.insert(lru.end(), key);
		cache[key].second = lru.end();
		cache[key].second--;

		// return value
		return result;
	}

	void put(int key, int value) {

		// update value if key already exists
		if (cache.find(key) != cache.end())
		{
			lru.erase(cache[key].second);
			cache[key].first = value;
			lru.insert(lru.end(), key);
			cache[key].second = lru.end();
			cache[key].second--;
			return;
		}

		// insert new key and value
		lru.insert(lru.end(), key);
		pair<int, list<int>::iterator> p(value, lru.end());
		p.second--;
		cache[key] = p;

		// delete lru if exceeding capacity
		if (lru.size() > cap)
		{
			cache.erase(lru.front());
			lru.erase(lru.begin());
		}
	}
};




































//class LRUCache {
//private:
//	
//	list<int> lru; // front is least recently used
//	map<int, list<int>::iterator> cache;
//	int cap;
//
//public:
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		// get the return value
//		map<int, list<int>::iterator>::iterator test = cache.find(key);
//		list<int>::iterator testb = cache[key];
//		if (cache[key] == lru.end())
//			return -1;
//
//		int ret = *cache[key];
//
//		// erase existing value in list
//		lru.erase(cache[key]);
//
//		// place value at back of list
//		lru.insert(lru.end(), ret);
//		list<int>::iterator last = lru.end();
//		last--;
//		cache[key] = last;
//
//		// return value
//		return ret;
//	}
//
//	void put(int key, int value) {
//		lru.insert(lru.end(), value);
//		list<int>::iterator last = lru.end();
//		last--;
//		cache[key] = last;
//		if (lru.size() > cap)
//		{
//			lru.erase(lru.begin());
//		}
//	}
//};









































//class LRUCache {
//public:
//	int cap;
//	LRUCache(int capacity) {
//		cap = capacity;
//	}
//
//	int get(int key) {
//		if (cache.count(key) <= 0)
//			return -1;
//
//		int res = cache[key].first;
//
//		//update lru
//		lru.erase(cache[key].second);
//		lru.push_front(key);
//		cache[key].second = lru.begin();
//
//		return res;
//	}
//
//	void set(int key, int value) {
//		//erase old key, val if it exists
//		if (cache.count(key) > 0)
//		{
//			lru.erase(cache[key].second);
//			cache.erase(key);
//		}
//
//
//		// insert new key,val
//		lru.push_front(key);
//		pair<int, list<int>::iterator > p;
//		p.first = value;
//		p.second = lru.begin();
//		cache[key] = p;
//
//		// get rid of lru
//		if (lru.size() > cap)
//		{
//			cache.erase(lru.back());
//			list<int>::iterator lruEnd = lru.end();
//			lruEnd--;
//			lru.erase(lruEnd);
//		}
//	}
//
//	list<int> lru; // keeps track of used order by key;
//	map<int, pair<int, list<int>::iterator> > cache;
//};
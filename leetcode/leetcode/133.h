#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include "Solution.h"

using namespace std;

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (node == NULL)
		return NULL;

	static map<int, UndirectedGraphNode*> nodeArchive;

	UndirectedGraphNode* u = new UndirectedGraphNode(node->label);
	u->neighbors = {};
	nodeArchive[u->label] = u;

	for (int i = 0; i < node->neighbors.size(); i++)
	{
		//if (node->neighbors[i]->label == u->label)
		//{
		//	u->neighbors.push_back(u);
		//}
		if (nodeArchive.count(node->neighbors[i]->label) > 0)
		{
			u->neighbors.push_back(nodeArchive[node->neighbors[i]->label]);
		}
		else
		{
			UndirectedGraphNode* nb = cloneGraph(node->neighbors[i]);
			u->neighbors.push_back(nb);
		}
	}
	
	return u;
}

UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
	if (node == NULL) return NULL;
	unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> mp;
	queue <UndirectedGraphNode*> q;
	q.push(node);
	UndirectedGraphNode* start = new UndirectedGraphNode(node->label);
	mp[node] = start;
	while (!q.empty()) {
		UndirectedGraphNode* original = q.front();
		UndirectedGraphNode* duplicate = mp[original];
		q.pop();
		for (int i = 0; i< original->neighbors.size(); i++) {
			if (mp.find(original->neighbors[i]) != mp.end()) {
				duplicate->neighbors.push_back(mp[original->neighbors[i]]);
			}
			else {
				UndirectedGraphNode* temp = new UndirectedGraphNode(original->neighbors[i]->label);
				duplicate->neighbors.push_back(temp);
				q.push(original->neighbors[i]);
				mp[original->neighbors[i]] = temp;
			}
		}
	}
	return start;
}

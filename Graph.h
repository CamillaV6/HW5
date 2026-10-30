#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;


#define nodekey_t unsigned long long int
#define INVALID_NODE_KEY ULLONG_MAX

//make sure every instance is created on the heap
struct GraphEdge {
	nodekey_t from;
	nodekey_t to;
	unsigned int weight;	
};

class Graph{
	
	public:
	
		~Graph();
		
		//should throw invalid argument if invalid argument given (duplicate key or not exist)
		void AddNode(nodekey_t key = 0);
		const GraphEdge* AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight = 0);
		
		//true if key is in graph
		bool IsPresent(nodekey_t key) const;
		
		//used for testing / debugging 
		string NodesToString() const;
		string EdgesToString() const;
		
		//get pointers of edges of neighbors
		set<const GraphEdge*> GetOutwardEdgesFrom(nodekey_t nodeKey) const;
		set<nodekey_t> GetNodes() const;
		
		size_t Size() const;
		size_t Order() const;
	
	private:
		vector<nodekey_t> nodes;
		
		vector<GraphEdge*> edges;
	
};

#endif

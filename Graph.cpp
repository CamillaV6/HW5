#include "Graph.h"

using namespace std;

Graph::~Graph() { //deconstructer
	for (GraphEdge* edge : edges) {
		delete edge;
	}
	edges.clear();
}

void Graph::AddNode(nodekey_t key){
	if (IsPresent(key)) {
		throw invalid_argument("node already exists");
	}
	nodes.push_back(key);
}

bool Graph::IsPresent(nodekey_t key) const {
	for (nodekey_t node : nodes) {
		if (node == key) {
			return true;
		} 
	}
	return false;
}
	
const GraphEdge* Graph::AddEdge(nodekey_t fromNodeKey, nodekey_t toNodeKey, unsigned int weight) {
	
	if (!IsPresent(toNodeKey) || !IsPresent(fromNodeKey)) {
		throw invalid_argument("node does not exist");
	}
	for (const GraphEdge* edge : edges) {
		if (edge->from == fromNodeKey && edge->to == toNodeKey) {
			throw invalid_argument("edge already exists between these nodes");
		}
	}
	
	GraphEdge* edge = new GraphEdge(); //adds to heap
	edge->from = fromNodeKey;
	edge->to = toNodeKey;
	edge->weight = weight;
	
	edges.push_back(edge); //pushes in vector
	return edge;
}

string Graph::NodesToString() const {
	
	string nodeString = "[";
	
	for (long unsigned int i = 0; i < nodes.size(); i ++) {
		if (i > 0) {
			nodeString += ", ";
		}
		nodeString += "(" + to_string(nodes[i]) + ")";
    }
    
    nodeString = nodeString + "]";
	
	return nodeString;
}

string Graph::EdgesToString() const {
	
	string edgeString = "[";
	
	for (long unsigned int i = 0; i < edges.size(); i ++) {
		if ( i > 0) {
			edgeString += ", ";
		}
		edgeString += "((" + to_string(edges[i]->from) + ")" +  "->" + "(" + to_string(edges[i]->to) + ") w:" + to_string(edges[i]->weight) + ")";
	}
	edgeString += "]";
	return edgeString;
}

set<const GraphEdge*> Graph::GetOutwardEdgesFrom(nodekey_t nodeKey) const{
	if(!IsPresent(nodeKey)) {
		throw invalid_argument("node does not exist");
	}
	
	set<const GraphEdge*> outwardEdges;
    for (const GraphEdge* edge : edges) {
        if (edge->from == nodeKey) { //if from edge is the same, node is a neighbor
            outwardEdges.insert(edge);
        }
    }
    return outwardEdges;
	
}

set<nodekey_t> Graph::GetNodes() const { //https://www.w3schools.com/cpp/cpp_sets.asp for sets
	set<nodekey_t> nodeSet;
	for (nodekey_t node : nodes) {
		nodeSet.insert(node);
	}
	return nodeSet;
}

size_t Graph::Size() const {
	return edges.size();
}

size_t Graph::Order() const {
	return nodes.size();
}

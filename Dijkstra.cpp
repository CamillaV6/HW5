#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

/*
 * The time comlexity is O(N^3)
 * The dijkstra loops through all nodes
 * For each node loops to get all neighbors
 * each neighbor loops to get all weights
 * there is a for loop, inside a for loop, inside a while loop
 */

using namespace std;

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) { //https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/ referenced this for algorithm
    if (g == nullptr || !g->IsPresent(start) || !g->IsPresent(end)) {
        return -1; //points don't exist
    }
    
    if (start == end) {
		return 0;
	}

    BetterPriorityQueue pq;

    for (nodekey_t key : g->GetNodes()) { //copies graph so that INT_MAX can be replaced later if edge exists
        BPQNode node;
        node.gnode = key;
        if (key == start) {
			node.pri = 0;
		}
        pq.push(node);
    }

    while (!pq.empty()) {
        BPQNode current = pq.top();
        pq.pop();

        nodekey_t curNode = current.gnode;
        int curDist = current.pri;

        if (curNode == end) { //reaching end
			if (curDist == INT_MAX) { //path doesn't exist
				return -1;
			}
			else {
				return curDist;
			}
        }

        for (const GraphEdge* edge : g->GetOutwardEdgesFrom(curNode)) { //creates a temp node that only updates pq if weight is priority is lower
            nodekey_t v = edge->to;
            int weight = edge->weight;

            BPQNode neighbor;
            neighbor.gnode = v;
            
            neighbor.pri = curDist + weight;
            pq.Update(neighbor);
        }
    }

    return -1;
}

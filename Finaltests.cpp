
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include "Dijkstra.h"

#include <iostream>
#include <cassert>

using namespace std;


int DijkstraTest(){
	cout << "Testing Dijkstra Algorithm..." << endl;
	
	// Test 1: graph from assignment
	Graph *g = new Graph();
	
	g->AddNode(1);
	g->AddNode(2);
	g->AddNode(3);
	
	g->AddEdge(1, 2, 7);
	g->AddEdge(2, 1, 7);
	g->AddEdge(1, 3, 9);
	g->AddEdge(3, 1, 9);

	
	cout <<  "---Graph---" << endl;
	cout << "\tnodes: " << g->NodesToString() << endl;
	cout << "\tedges: " << g->EdgesToString() << endl;
	cout << "---Graph---" << endl << endl;

	nodekey_t start = 1;
	nodekey_t end = 3;

	cout << "start: " << to_string(start) << "  goal: " << to_string(end) << endl;
	
	int ans = dijkstra(start, end, g);
	cout << "Output from Dijkstra(" << to_string(start) << ", " << to_string(end) << ") => " << ans << endl;
	assert(ans == 9);

	delete g;
	
	cout << "DONE with basic testing of Dijkstra algorithm" << endl;
	
	return ans;
}

void Finaltests() { //used gemini to help create tests
    std::cout << "Running Dijkstra Algorithm Tests..." << std::endl;
    
    Graph g1; //simple
    g1.AddNode(1);
    g1.AddNode(2);
    g1.AddNode(3);

    g1.AddEdge(1, 2, 5); 
    g1.AddEdge(2, 3, 10);

    assert(dijkstra(1, 3, &g1) == 15);
    assert(dijkstra(1, 1, &g1) == 0);

    Graph g2;
    g2.AddNode(1);
    g2.AddNode(2);
    g2.AddNode(3);
    g2.AddNode(4);

    g2.AddEdge(1, 2, 5);
    g2.AddEdge(1, 3, 10);
    g2.AddEdge(3, 2, 1);
    g2.AddEdge(2, 4, 2);
    g2.AddEdge(3, 4, 6);

    assert(dijkstra(1, 4, &g2) == 7);

    Graph g3; //unreachable node
    g3.AddNode(10);
    g3.AddNode(20);
    g3.AddNode(30);

    g3.AddEdge(10, 20, 4);

    assert(dijkstra(10, 20, &g3) == 4);
    assert(dijkstra(10, 30, &g3) == -1);

    Graph g4; //graph loops on itself
    g4.AddNode(1);
    g4.AddNode(2);
    g4.AddNode(3);

    g4.AddEdge(1, 2, 3);
    g4.AddEdge(2, 3, 4);
    g4.AddEdge(3, 1, 2);

    assert(dijkstra(1, 3, &g4) == 7);
    assert(dijkstra(2, 1, &g4) == 6); // 2 -> 3 -> 1 (4 + 2)

    assert(dijkstra(1, 999, &g1) == -1); // 999 does not exist
    assert(dijkstra(1, 2, nullptr) == -1); // Null pointer check
}



int main(){
	
	DijkstraTest(); // this one by itself tests the graph on the assignment
	cout << endl;
	Finaltests();
	cout << "ALL TESTS PASSED!" << endl;

	return 0;
}

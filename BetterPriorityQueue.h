#ifndef BETTER_PRIORITY_QUEUE_H
#define BETTER_PRIORITY_QUEUE_H

#include <iostream>
#include <queue>
#include <climits>

#include "Graph.h"

using namespace std;

struct BPQNode {
    int pri = INT_MAX;
    bool visited = false;
    nodekey_t gnode = INVALID_NODE_KEY;

    // Min-heap comparison (smaller pri comes out first)
    bool operator<(const BPQNode &other) const {
        return pri > other.pri;
    }

    bool operator>(const BPQNode &other) const {
        return pri < other.pri;
    }

    // Equality based on node key (gnode)
    bool operator==(const BPQNode &other) const {
        return this->gnode == other.gnode;
    }
};

class BetterPriorityQueue : public priority_queue<BPQNode> {
public:
    static string BPQNodeToString(const BPQNode& node);

    bool Contains(const BPQNode& node) const;
    bool Update(const BPQNode& dummy);
    string ToString() const;
};

#endif

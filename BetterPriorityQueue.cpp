#include "BetterPriorityQueue.h"

using namespace std;

bool BetterPriorityQueue::Contains(const BPQNode& node) const {
    for (const BPQNode& item : this->c) {
        if (item == node) {
            return true;
        }
    }
    return false;
}

bool BetterPriorityQueue::Update(const BPQNode& dummy) {
    bool found = false;
    for (const auto& item : this->c) {
        if (item == dummy) {
            if (item.pri <= dummy.pri) {
                return false; //not changed
            }
            found = true;
        }
    }

    if (!found) {
        return false; //not found
    }

    BetterPriorityQueue temp;

    while (!this->empty()) { //loops through this queue and pushes to temp but changes priority of node
        BPQNode topNode = this->top();
        this->pop();

        if (topNode == dummy) {
            topNode.pri = dummy.pri;
        }

        temp.push(topNode);
    }
    this->swap(temp); //swaps, https://www.geeksforgeeks.org/cpp/priority-queue-in-cpp-stl/ for queue functions
    
    return true;
}

string BetterPriorityQueue::ToString() const {
    string result = "[";
    for (size_t i = 0; i < this->c.size(); ++i) {
        if (i > 0) {
            result += ", ";
        }
        result += BPQNodeToString(this->c[i]);
    }
    result += "]";
    return result;
}

string BetterPriorityQueue::BPQNodeToString(const BPQNode& node) {
    return "(" + to_string(node.gnode) + ", pri: " + to_string(node.pri) + ")";
}

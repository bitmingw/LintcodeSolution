#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        deque<DirectedGraphNode*> graphq;
        set<DirectedGraphNode*> visited;
        graphq.push_back(s);
        visited.insert(s);
        while (graphq.size()) {
            DirectedGraphNode* node = graphq.front();
            graphq.pop_front();
            if (node == t) return true;
            for (auto neighbor: node->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    graphq.push_back(neighbor);
                }
            }
        }
        return false;
    }
};



int main() {
    Solution s;
    return 0;
}

#include <vector>
#include <deque>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;

        // create a map for original graph
        map<int, UndirectedGraphNode*> mnode;
        deque<UndirectedGraphNode*> qnode;
        qnode.push_back(node);
        while (qnode.size()) {
            UndirectedGraphNode* current = qnode.front();
            qnode.pop_front();
            if (mnode.find(current->label) == mnode.end()) {
                mnode[current->label] = current;
            }
            for (auto neighbor: current->neighbors) {
                if (mnode.find(neighbor->label) == mnode.end()) {
                    mnode[neighbor->label] = neighbor;
                    qnode.push_back(neighbor);
                }
            }
        }

        // create a map for new graph
        map<int, UndirectedGraphNode*> cmnode;
        for (auto it = mnode.begin(); it != mnode.end(); ++it) {
            cmnode[it->first] = new UndirectedGraphNode(it->first);
        }
        for (auto it = mnode.begin(); it != mnode.end(); ++it) {
            auto neighbors = it->second->neighbors;
            for (auto neighbor: neighbors) {
                int nlabel = neighbor->label;
                cmnode[it->first]->neighbors.push_back(cmnode[nlabel]);
            }
        }

        return cmnode[node->label];
    }
};

int main() {
    Solution s;
    return 0;
}

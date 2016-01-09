#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

// Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> topo;
        if (!graph.size()) return topo;
        // find the starting point
        map<DirectedGraphNode*, int> isStart;
        for (int i = 0; i < graph.size(); ++i) {
            isStart[graph[i]] = 0;
        }
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i]->neighbors.size(); ++j) {
                ++isStart[graph[i]->neighbors[j]];  // in-degree
            }
        }
        DirectedGraphNode *node;
        while (isStart.size()) {
            for (auto git = isStart.begin(); git != isStart.end(); ++git) {
                if (git->second == 0) {
                    node = git->first;
                    topo.push_back(node);
                    for (auto git2 = node->neighbors.begin(); git2 != node->neighbors.end(); ++git2) {
                        --isStart[*git2];
                    }
                    isStart.erase(git);
                    break;
                }
            }
        }
        return topo;
    }
};

int main() {
    Solution s;
    vector<DirectedGraphNode *> g;
    g.push_back(new DirectedGraphNode(0));
    g.push_back(new DirectedGraphNode(1));
    vector<DirectedGraphNode*> v = s.topSort(g);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i]->label << " ";
    }
    cout << endl;
    return 0;
}

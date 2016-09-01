#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n < 1) return false;
        if (n == 1 && edges.empty()) return true;
        else if (edges.empty()) return false;
        queue<int> nodes;
        vector<bool> visited(n, false);
        nodes.push(edges[0][0]);
        while (nodes.size()) {
            int wanted = nodes.front();
            nodes.pop();
            if (visited[wanted]) return false;
            visited[wanted] = true;
            for (int i = 0; i < edges.size(); ++i) {
                if (edges[i][0] == wanted) {
                    nodes.push(edges[i][1]);
                    edges.erase(edges.begin() + i);
                    --i;
                } else if (edges[i][1] == wanted) {
                    nodes.push(edges[i][0]);
                    edges.erase(edges.begin() + i);
                    --i;
                }
            }
        }
        if (edges.empty()) {
            for (auto v: visited) {
                if (!v) return false;
            }
            return true;
        }
        else return false;
    }
};

int main() {
    Solution s;
    return 0;
}

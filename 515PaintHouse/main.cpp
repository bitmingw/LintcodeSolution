#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        int nhouse = costs.size();
        if (nhouse == 0) return 0;
        vector<vector<int>> accu(nhouse, vector<int>(3, 0));
        accu[0][0] = costs[0][0];
        accu[0][1] = costs[0][1];
        accu[0][2] = costs[0][2];
        for (int i = 1; i < nhouse; ++i) {
            accu[i][0] = min(accu[i-1][1], accu[i-1][2]) + costs[i][0];
            accu[i][1] = min(accu[i-1][0], accu[i-1][2]) + costs[i][1];
            accu[i][2] = min(accu[i-1][0], accu[i-1][1]) + costs[i][2];
        }
        return min(min(accu[nhouse-1][0], accu[nhouse-1][1]), accu[nhouse-1][2]);
    }
};

int main() {
    Solution s;
    return 0;
}

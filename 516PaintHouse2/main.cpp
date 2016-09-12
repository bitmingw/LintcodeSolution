#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int n = costs.size();
        int k = costs[0].size();
        if (k == 1) return costs[0][0];
        int min_val1 = INT32_MAX;
        int min_val2 = INT32_MAX;
        int min_idx1 = -1;
        int min_idx2 = -1;
        for (int j = 0; j < k; ++j) {
            int val = costs[0][j];
            if (val < min_val1) {
                min_val2 = min_val1;
                min_idx2 = min_idx1;
                min_val1 = val;
                min_idx1 = j;
            } else if (val < min_val2) {
                min_val2 = val;
                min_idx2 = j;
            }
        }
        for (int i = 1; i < n; ++i) {
            vector<int> res(costs[i].begin(), costs[i].end());
            for (int j = 0; j < k; ++j) {
                if (j == min_idx1) {
                    res[j] += min_val2;
                } else {
                    res[j] += min_val1;
                }
            }
            min_val1 = INT32_MAX;
            min_val2 = INT32_MAX;
            for (int j = 0; j < k; ++j) {
                int val = res[j];
                if (val < min_val1) {
                    min_val2 = min_val1;
                    min_idx2 = min_idx1;
                    min_val1 = val;
                    min_idx1 = j;
                } else if (val < min_val2) {
                    min_val2 = val;
                    min_idx2 = j;
                }
            }
        }
        return min_val1;
    }
};

int main() {
    Solution s;
    return 0;
}

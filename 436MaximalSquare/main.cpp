#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> end_dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) end_dp[i][0] = matrix[i][0];
        for (int j = 0; j < n; ++j) end_dp[0][j] = matrix[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) end_dp[i][j] = 0;
                else end_dp[i][j] = 1 + min(min(end_dp[i-1][j], end_dp[i][j-1]), end_dp[i-1][j-1]);
            }
        }
        int max_len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (end_dp[i][j] > max_len) max_len = end_dp[i][j];
            }
        }
        return max_len * max_len;
    }
};

int main() {
    Solution s;
    return 0;
}

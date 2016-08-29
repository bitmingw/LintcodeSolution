#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<bool>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (grid[i][j] == false) return;
        grid[i][j] = false;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

int main() {
    Solution s;
    return 0;
}

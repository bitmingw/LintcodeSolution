#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        int nrow = grid.size();
        if (nrow == 0) return 0;
        int ncol = grid[0].size();
        if (ncol == 0) return 0;
        vector<vector<int>> dpGrid(nrow, vector<int>(ncol, 0));
        for (int i = 0; i < nrow; ++i) {
            for (int j = 0; j < ncol; ++j) {
                if (i == 0 && j == 0) {
                    dpGrid[0][0] = grid[0][0];
                } else if (i == 0 && j > 0) {
                    dpGrid[i][j] = dpGrid[i][j-1] + grid[i][j];
                } else if (i > 0 && j == 0) {
                    dpGrid[i][j] = dpGrid[i-1][j] + grid[i][j];
                } else {
                    dpGrid[i][j] = min(dpGrid[i-1][j], dpGrid[i][j-1]) + grid[i][j];
                }
            }
        }
        return dpGrid[nrow-1][ncol-1];
    }
};

int main() {
    Solution s;
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // assume obstacleGrid is not empty
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> accuGrid(m, vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) accuGrid[0][j] = 1;
            else break;
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) accuGrid[i][0] = 1;
            else break;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0)
                    accuGrid[i][j] = accuGrid[i-1][j] + accuGrid[i][j-1];
            }
        }

        return accuGrid[m-1][n-1];
    }
};

int main() {
    Solution s;
    return 0;
}

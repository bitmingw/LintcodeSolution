#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m+2, vector<int>(n+2));
        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (matrix[i-1][j-1] == 0) mat[i][j] = 0;
                else mat[i][j] = mat[i-1][j] + 1;
            }
        }
        int maxsize = 0;
        for (int i = 1; i < m+1; ++i) {
            stack<int> heights;
            for (int j = 1; j <= n+1; ++j) {
                while (heights.size() && mat[i][j] <= mat[i][heights.top()]) {
                    int h = mat[i][heights.top()];
                    heights.pop();
                    int w = heights.empty() ? j-1 : j - heights.top() - 1;
                    int s = h * w;
                    maxsize = max(maxsize, s);
                }
                heights.push(j);
            }
        }
        return maxsize;
    }
};

int main() {
    Solution s;
    return 0;
}

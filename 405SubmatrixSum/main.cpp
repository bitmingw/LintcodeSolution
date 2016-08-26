#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (matrix.empty()) return ans;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sum_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum_matrix[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                sum_matrix[i][j] += sum_matrix[i][j-1];
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                sum_matrix[i][j] += sum_matrix[i-1][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = i; k < m; ++k) {
                    for (int l = j; l < n; ++l) {
                        if (i == k && j == l) {
                            if (matrix[i][j] == 0) {
                                ans = {{i, j}, {i, j}};
                                return ans;
                            }
                        } else if (i == k) {
                            if (sum_matrix[i][j] == sum_matrix[i][l]) {
                                ans = {{0, j+1}, {i, l}};
                                return ans;
                            }
                        } else if (j == l) {
                            if (sum_matrix[i][j] == sum_matrix[k][j]) {
                                ans = {{i+1, 0}, {k, j}};
                                return ans;
                            }
                        } else {
                            if (sum_matrix[i][j] + sum_matrix[k][l] == sum_matrix[i][l] + sum_matrix[k][j]) {
                                ans = {{i+1, j+1}, {k, l}};
                                return ans;
                            }
                        }
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        int mat[100][100];
        for (int i = 0; i < 100; ++i) {
            mat[0][i] = 1;
        }
        for (int i = 1; i < 100; ++i) {
            mat[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};

int main() {
    Solution s;
    return 0;
}

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        set<int> zero_row;
        set<int> zero_col;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }
        for (int r: zero_row) {
            for (int j = 0; j < n; ++j) {
                matrix[r][j] = 0;
            }
        }
        for (int c: zero_col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

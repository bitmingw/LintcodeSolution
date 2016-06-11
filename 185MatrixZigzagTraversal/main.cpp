#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> res;
        if (matrix.size() == 0) return res;
        
        int m = matrix.size();  // number of rows
        int n = matrix[0].size();  // number of columns
        int idx_max = m + n - 2;  // max possible index of i + j
        
        for (int idx = 0; idx <= idx_max; ++idx) {
            if (idx % 2 == 0) {
                int begin = (idx - (m - 1) > 0) ? idx - m + 1 : 0;
                int end = (idx - (n - 1) > 0) ? n - 1 : idx;
                for (int j = begin; j <= end; ++j) {
                    int i = idx - j;
                    res.push_back(matrix[i][j]);
                }
            } else {
                int begin = (idx - (n - 1) > 0) ? idx - n + 1 : 0;
                int end = (idx - (m - 1) > 0) ? m - 1 : idx;
                for (int i = begin; i <= end; ++i) {
                    int j = idx - i;
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

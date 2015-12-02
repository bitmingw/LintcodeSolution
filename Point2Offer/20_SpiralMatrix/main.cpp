#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = vector<int>();
        if (matrix.size() == 0 || matrix[0].size() == 0) return result;
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        int i = 0; // start row index
        int j = -1; // start col index
        int n_decrease = 1; // row indent level
        int c_decrease = 0; // col indent level
        while (true) {
            for (int k = 1; k <= ncol - c_decrease; ++k) {
                ++j;
                result.push_back(matrix[i][j]);
            }
            ++c_decrease;
            if (ncol - c_decrease < 0) break;
            for (int k = 1; k <= nrow - n_decrease; ++k) {
                ++i;
                result.push_back(matrix[i][j]);
            }
            ++n_decrease;
            if (nrow - n_decrease < 0) break;
            for (int k = 1; k <= ncol - c_decrease; ++k) {
                --j;
                result.push_back(matrix[i][j]);
            }
            ++c_decrease;
            if (ncol - c_decrease < 0) break;
            for (int k = 1; k <= nrow - n_decrease; ++k) {
                --i;
                result.push_back(matrix[i][j]);
            }
            ++n_decrease;
            if (nrow - n_decrease < 0) break;
        }
        return result;
    }
};


int main() {
    int r1[] = {1, 2, 3, 4};
    int r2[] = {5, 6, 7, 8};
    int r3[] = {9, 10, 11, 12};
    vector<int> v1 = vector<int>(r1, r1+sizeof(r1)/sizeof(int));
    vector<int> v2 = vector<int>(r2, r2+sizeof(r2)/sizeof(int));
    vector<int> v3 = vector<int>(r3, r3+sizeof(r3)/sizeof(int));
    vector<vector<int>> mat = vector<vector<int>>();
    mat.push_back(v1);
    mat.push_back(v2);
    mat.push_back(v3);
    Solution s;
    vector<int> result = s.spiralOrder(mat);
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

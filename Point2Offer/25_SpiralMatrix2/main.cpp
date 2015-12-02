#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // generate all zero matrix
        vector<vector<int>> mat = vector<vector<int>>();
        for (int i = 0; i < n; ++i) {
            vector<int> line = vector<int>(n, 0);
            mat.push_back(line);
        }
        // set parameters
        int i = 0; // row index
        int j = -1; // col index
        int r_dec = 1; // deducted rows
        int c_dec = 0; // deducted cols
        int num = 1; // the number to be inserted
        while (true) {
            for (int k = 1; k <= n - c_dec; ++k) {
                ++j;
                mat[i][j] = num++;
            }
            ++c_dec;
            if (n - c_dec < 0) break;
            for (int k = 1; k <= n - r_dec; ++k) {
                ++i;
                mat[i][j] = num++;
            }
            ++r_dec;
            if (n - r_dec < 0) break;
            for (int k = 1; k <= n - c_dec; ++k) {
                --j;
                mat[i][j] = num++;
            }
            ++c_dec;
            if (n - c_dec < 0) break;
            for (int k = 1; k <= n - r_dec; ++k) {
                --i;
                mat[i][j] = num++;
            }
            ++r_dec;
            if (n - r_dec < 0) break;
        }
        return mat;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = s.generateMatrix(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

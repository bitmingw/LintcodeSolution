#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // assume both S and T are not empty
        int n = S.length();
        int m = T.length();
        if (m == 0) return 1;
        if (m > n) return 0;
        vector<vector<int>> mat(m, vector<int>(n, 0));

        if (S[0] == T[0]) mat[0][0] = 1;
        for (int j = 1; j < n; ++j) {
            if (S[j] != T[0]) mat[0][j] = mat[0][j-1];
            else mat[0][j] = mat[0][j-1] + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = i; j < n; ++j) {
                if (S[j] != T[i]) mat[i][j] = mat[i][j-1];
                else mat[i][j] = mat[i-1][j-1] + mat[i][j-1];
            }
        }

        return mat[m-1][n-1];
    }
};

int main() {
    Solution s;
    return 0;
}

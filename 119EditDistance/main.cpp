#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0 || len2 == 0) return abs(len1 - len2);
        vector<vector<int>> mat(len2+1, vector<int>(len1+1, 0));

        for (int j = 1; j <= len1; ++j) {
            mat[0][j] = j;
        }
        for (int i = 1; i <= len2; ++i) {
            mat[i][0] = i;
        }
        for (int i = 1; i <= len2; ++i) {
            for (int j = 1; j <= len1; ++j) {
                if (word1[j-1] != word2[i-1])
                    mat[i][j] = min(min(mat[i-1][j], mat[i][j-1]), mat[i-1][j-1]) + 1;
                else
                    mat[i][j] = min(min(mat[i-1][j] + 1, mat[i][j-1] + 1), mat[i-1][j-1]);
            }
        }

        return mat[len2][len1];
    }
};

int main() {
    Solution s;
    return 0;
}

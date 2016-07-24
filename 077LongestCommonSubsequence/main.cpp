#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.length() == 0 || B.length() == 0) return 0;
        vector<vector<int>> matrix(A.length(), vector<int>(B.length(), 0));

        // the first element
        A[0] == B[0] ? matrix[0][0] = 1 : matrix[0][0] = 0;
        // the first row
        for (int j = 1; j < B.length(); ++j) {
            matrix[0][j] = matrix[0][j-1];
            if (A[0] == B[j] && matrix[0][j] < 1) matrix[0][j] = 1;
        }
        // the first column
        for (int i = 1; i < A.length(); ++i) {
            matrix[i][0] = matrix[i-1][0];
            if (A[i] == B[0] && matrix[i][0] < 1) matrix[i][0] = 1;
        }
        // center
        for (int i = 1; i < A.length(); ++i) {
            for (int j = 1; j < B.length(); ++j) {
                if (A[i] == B[j]) {
                    matrix[i][j] = max(matrix[i-1][j-1] + 1, max(matrix[i-1][j], matrix[i][j-1]));
                } else {
                    matrix[i][j] = max(matrix[i-1][j-1], max(matrix[i-1][j], matrix[i][j-1]));
                }
            }
        }
        int res = matrix[A.length() - 1][B.length() - 1];
        return res;
    }
};

int main() {
    Solution s;
	return 0;
}

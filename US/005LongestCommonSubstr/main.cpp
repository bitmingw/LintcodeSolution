#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (!A.size() || !B.size()) return 0;
        // build the matrix for dynamic programming
        vector<vector<int>> board;
        vector<int> line = vector<int>(B.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            board.push_back(line);
        }
        // do dynamic programming
        int max_len = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = board[i-1][j-1] + 1;
                    }
                    if (board[i][j] > max_len) {
                        max_len = board[i][j];
                    }
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    string s1 = "ABCD", s2 = "CBCE";
    cout << s.longestCommonSubstring(s1, s2) << endl;  // should be 2
    return 0;
}

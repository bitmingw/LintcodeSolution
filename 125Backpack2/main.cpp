#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // assume A, V are not empty and m > 0
        vector<vector<int>> bp(A.size(), vector<int>(m+1, 0));
        for (int j = A[0]; j <= m; ++j) {
            bp[0][j] = V[0];
        }
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j < A[i]) {
                    bp[i][j] = bp[i-1][j];
                } else {
                    bp[i][j] = max(bp[i-1][j], bp[i-1][j-A[i]] + V[i]);
                }
            }
        }
        return bp[A.size()-1][m];
    }
};

int main() {
    Solution s;
    return 0;
}

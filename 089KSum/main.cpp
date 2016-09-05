#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        if (k == 0) return 0;
        vector<vector<int>> table(k+1, vector<int>(target+1, 0));
        table[0][0] = 1;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = k; j > 0; --j) {
                for (int kk = target; kk >= A[i]; --kk) {
                    table[j][kk] += table[j-1][kk - A[i]];
                }
            }
        }
        return table[k][target];
    }
};

int main() {
    Solution s;
    return 0;
}

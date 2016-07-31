#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        if (A.empty()) return 0;

        // assume all elements in A are not greater than 100
        vector<vector<int>> matrix(101, vector<int>(A.size(), 0));
        
        for (int i = 0; i < 101; ++i) {
            matrix[i][0] = abs(i - A[0]);
        }
        for (int j = 1; j < A.size(); ++j) {
            for (int i = 0; i < 101; ++i) {
                int start_idx = max(i - target, 0);
                int end_idx = min(i + target, 100);
                int min_val = matrix[start_idx][j-1];
                for (int k = start_idx + 1; k <= end_idx; ++k) {
                    if (matrix[k][j-1] < min_val) min_val = matrix[k][j-1];
                }
                matrix[i][j] = min_val + abs(i - A[j]);
            }
        }

        int min_val = matrix[0][A.size()-1];
        for (int i = 1; i < 101; ++i) {
            if (matrix[i][A.size()-1] < min_val) min_val = matrix[i][A.size()-1];
        }
        return min_val;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 4, 2, 3};
    cout << s.MinAdjustmentCost(A, 1) << endl;  // should be 2
    return 0;
}

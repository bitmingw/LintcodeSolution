#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        if (A.empty() && B.empty()) return 0.0;
        int total_sz = A.size() + B.size();
        if (total_sz % 2 == 1) {
            return findKth(A, B, 0, 0, (total_sz+1)/2);
        } else {
            return (findKth(A, B, 0, 0, total_sz/2) + \
                    findKth(A, B, 0, 0, total_sz/2+1)) / 2;
        }
    }

    double findKth(vector<int>& A, vector<int>& B, int A_start, int B_start, int k) {
        if (A_start >= A.size()) return B[B_start + k - 1];
        if (B_start >= B.size()) return A[A_start + k - 1];
        if (k == 1) return min(A[A_start], B[B_start]);
        int A_key, B_key;
        if (A_start + k/2 - 1 >= A.size()) A_key = INT32_MAX;
        else A_key = A[A_start + k/2 - 1];
        if (B_start + k/2 - 1 >= B.size()) B_key = INT32_MAX;
        else B_key = B[B_start + k/2 - 1];
        if (A_key > B_key) return findKth(A, B, A_start, B_start + k/2, k - k/2);
        else return findKth(A, B, A_start + k/2, B_start, k - k/2);
    }
};

int main() {
    Solution s;
    return 0;
}

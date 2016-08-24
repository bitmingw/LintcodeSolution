#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // assume A and B are not empty
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int lenA = A.size();
        int lenB = B.size();
        int idxA = 0;
        int idxB = 0;
        int min_diff = INT32_MAX;
        while (idxA < lenA && idxB < lenB) {
            int diff = abs(A[idxA] - B[idxB]);
            if (diff < min_diff) min_diff = diff;
            if (A[idxA] < B[idxB]) {
                ++idxA;
            } else if (A[idxA] > B[idxB]) {
                ++idxB;
            } else {
                break;
            }
        }
        return min_diff;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    /**
     * Explanation of algorithm:
     * The missing value should be in range of 1 - n
     * First change all value <= 0 && > n to invalid (say n+1)
     * Go though each valid value, mark the element that having the index as negative
     * Return the index of first non-negative element
     */
    int firstMissingPositive(vector<int> A) {
        if (!A.size()) return 1;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] < 1 || A[i] > n) A[i] = n+1;  // invalid value
        }
        int x;
        for (int i = 0; i < n; ++i) {
            x = abs(A[i]);
            if (x == n+1) continue;
            if (A[x-1] > 0) A[x-1] = -A[x-1];
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) return i+1;
        }
        return n+1;
    }
};

int main() {
    Solution s;
    return 0;
}

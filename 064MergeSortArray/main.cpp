#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int a_idx = m-1, b_idx = n-1, m_idx = m+n-1;
        while (a_idx >= 0 && b_idx >= 0) {
            if (A[a_idx] > B[b_idx]) {
                A[m_idx--] = A[a_idx--];
            } else {
                A[m_idx--] = B[b_idx--];
            }
        }
        while (b_idx >= 0) {
            A[m_idx--] = B[b_idx--];
        }
    }
};

int main() {
    Solution s;
    return 0;
}

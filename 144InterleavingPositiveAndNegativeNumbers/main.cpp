#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        if (A.size() < 2) return;

        vector<int> sortedA(A.begin(), A.end());
        sort(sortedA.begin(), sortedA.end());
        int neg_idx = 0;
        int pos_idx = A.size() - 1;
        int current_idx = 0;
        int first_flag = (sortedA[sortedA.size()/2] > 0) ? 1 : 0;
        while (current_idx < A.size()) {
            if (current_idx % 2 == first_flag) {
                A[current_idx++] = sortedA[neg_idx++];
            } else {
                A[current_idx++] = sortedA[pos_idx--];
            }
        }
        return;
    }
};

int main() {
    Solution s;
    return 0;
}

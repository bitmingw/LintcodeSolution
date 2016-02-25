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
        int count = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A.size() - i >= k) {
                kSum(A, k-1, target-A[i], i+1, count);
            }
        }
        return count;
    }

    void kSum(vector<int>& A, int k, int target, int idx, int& count) {
        if (k == 0 && target == 0) {
            ++count;
            return;
        }
        for (int i = idx; i < A.size(); ++i) {
            if (A.size() - i >= k) {
                kSum(A, k-1, target-A[i], i+1, count);
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

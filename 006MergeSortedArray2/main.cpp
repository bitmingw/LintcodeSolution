#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        if (A.empty()) return B;
        if (B.empty()) return A;
        vector<int> res;
        int idxA = 0, idxB = 0;
        while (idxA < A.size() && idxB < B.size()) {
            if (A[idxA] <= B[idxB]) {
                res.push_back(A[idxA]);
                ++idxA;
            } else {
                res.push_back(B[idxB]);
                ++idxB;
            }
        }
        while (idxA < A.size()) {
            res.push_back(A[idxA++]);
        }
        while (idxB < B.size()) {
            res.push_back(B[idxB++]);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

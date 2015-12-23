#include <vector>
#include <iostream>
using namespace std;

class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        if (!A.size()) return -1;
        int lo = 0, hi = A.size() - 1;
        int mi = lo + (hi - lo) / 2;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (A[mi] == target) return mi;
            if (A[mi] > target && target >= A[0]) hi = mi - 1;
            else if (A[mi] > target && target < A[0] && A[mi] >= A[0]) lo = mi + 1;
            else if (A[mi] > target && target < A[0] && A[mi] < A[0]) hi = mi - 1;
            else if (A[mi] < target && target < A[0]) lo = mi + 1;
            else if (A[mi] < target && target >= A[0] && A[mi] < A[0]) hi = mi - 1;
            else if (A[mi] < target && target >= A[0] && A[mi] >= A[0]) lo = mi + 1;
        }
        if (A[lo] != target) return -1;
        else return lo;
    }
};

int main() {
    Solution s;
    return 0;
}

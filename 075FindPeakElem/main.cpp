#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int lo = 0, hi = A.size() - 1;
        int mi;
        while (lo < hi) {
            mi = lo + (hi - lo) / 2;
            if (A[mi] > A[mi+1]) hi = mi;
            else lo = mi + 1;
        }
        // now we should have hi == lo
        return lo;
    }
};

int main() {
    Solution s;
	return 0;
}

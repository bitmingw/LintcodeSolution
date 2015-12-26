#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int idx = 0, maxDist = 0;
        for (; idx < A.size() - 1; ++idx) {
            maxDist = max(maxDist, A[idx]) - 1;
            if (maxDist < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

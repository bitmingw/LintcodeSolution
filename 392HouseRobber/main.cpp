#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        if (A.empty()) return 0;
        if (A.size() == 1) return A[0];
        vector<long long> values(A.size(), 0);
        values[0] = A[0];
        values[1] = max(A[0], A[1]);
        for (int i = 2; i < values.size(); ++i) {
            values[i] = max(values[i-1], values[i-2] + A[i]);
        }
        return values[values.size() - 1];
    }
};

int main() {
    Solution s;
    return 0;
}

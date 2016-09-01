#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (k == 1) {
            if (n == 2) return 1;
            else return 0;
        }
        vector<int> sub(n);
        sub[0] = k;
        sub[1] = k * k;
        for (int i = 2; i < n; ++i) {
            sub[i] = (k-1) * sub[i-2] + (k-1) * sub[i-1];
        }
        return sub[n-1];
    }
};

int main() {
    Solution s;
    return 0;
}

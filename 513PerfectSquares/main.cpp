#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        vector<int> seq(n+1, INT32_MAX);
        seq[0] = 0;
        seq[1] = 1;
        for (int i = 1; i*i <= n; ++i) {
            int k = i*i;
            for (int j = k; j <= n; ++j) {
                if (seq[j] > seq[j-k] + 1)
                    seq[j] = seq[j-k] + 1;
            }
        }
        return seq[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}

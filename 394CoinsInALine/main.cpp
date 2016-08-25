#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        if (n == 1) return true;
        if (n == 2) return true;
        vector<bool> table(n+1, false);
        table[1] = true;
        table[2] = true;
        for (int i = 3; i <= n; ++i) {
            if (table[i-2] && table[i-1]) table[i] = false;
            else table[i] = true;
        }
        return table[n];
    }
};

int main() {
    Solution s;
    return 0;
}

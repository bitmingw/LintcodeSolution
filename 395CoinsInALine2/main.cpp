#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n == 1 || n == 2) return true;
        vector<int> rtotal(n, 0);
        rtotal[n-1] = values[n-1];
        for (int i = n-2; i >= 0; --i) {
            rtotal[i] = rtotal[i+1] + values[i];
        }
        vector<int> optimal(n, 0);
        optimal[n-1] = rtotal[n-1];
        optimal[n-2] = rtotal[n-2];
        for (int i = n-3; i >= 0; --i) {
            optimal[i] = max(rtotal[i] - optimal[i+1], rtotal[i] - optimal[i+2]);
        }
        if (optimal[0] >= rtotal[0] - optimal[0]) return true;
        else return false;
    }
};

int main() {
    Solution s;
    return 0;
}

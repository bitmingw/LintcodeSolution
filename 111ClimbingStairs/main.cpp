#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n == 0) return 1;
        vector<int> lookTable;
        lookTable.push_back(1);
        lookTable.push_back(2);
        for (int i = 2; i < n; ++i) {
            lookTable.push_back(lookTable[i-2] + lookTable[i-1]);
        }
        return lookTable[n-1];
    }
};

int main() {
	Solution s;
	return 0;
}

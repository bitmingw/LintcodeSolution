#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> lookTable;
        lookTable.push_back(1);
        lookTable.push_back(1);
        lookTable.push_back(2);
        int num;
        for (int idx = 3; idx <= n; ++idx) {
            num = 0;
            for (int i = 0; i < idx; ++i) {
                num += lookTable[i] * lookTable[idx-i-1];
            }
            lookTable.push_back(num);
        }
        return lookTable.back();
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;  // should be 5
    cout << s.numTrees(5) << endl;  // should be 42
    return 0;
}

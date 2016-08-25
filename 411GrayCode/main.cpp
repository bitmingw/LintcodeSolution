#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> codes;
        if (n == 0) {
            codes.push_back(0);
            return codes;
        }
        if (n == 1) {
            codes.push_back(0);
            codes.push_back(1);
            return codes;
        }
        codes = grayCode(n - 1);
        vector<int> mirror;
        for (auto it = codes.rbegin(); it != codes.rend(); ++it) {
            mirror.push_back(*it);
        }
        for (auto elem: mirror) {
            elem += (1 << (n-1));
            codes.push_back(elem);
        }
        return codes;
    }
};

int main() {
    Solution s;
    return 0;
}

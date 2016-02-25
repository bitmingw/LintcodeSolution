#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits);
        if (result.empty()) return result;
        int localSum = 0, carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            localSum = result[i] + carry;
            if (localSum > 9) {
                localSum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result[i] = localSum;
        }
        if (carry) result.insert(result.begin(), carry);
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

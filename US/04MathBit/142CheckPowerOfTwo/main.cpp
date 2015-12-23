#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    // Note: 1 is a power of 2!
    // Negative number is not a power of 2
    bool checkPowerOf2(int n) {
        if (n & 0x80000000) return false;
        return count1(n) == 1;
    }

    int count1(int n) {
        // assume the MSB is 0
        int count = n & 1;
        for (int i = 1; i < 32; ++i) {
            n = n >> 1;
            count += n & 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    return 0;
}

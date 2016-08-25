#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend ^ divisor) >> 31) sign = -1;
        if (divisor == 0) return INT32_MAX;
        long long udividend = (dividend > 0) ? dividend : - (long long) dividend;
        long long udivisor = (divisor > 0) ? divisor : - (long long) divisor;
        int shift = 31;
        long long res = 0;
        while (shift >= 0) {
            if (udividend >= udivisor << shift) {
                udividend -= udivisor << shift;
                res += 1LL << shift;
            }
            --shift;
        }
        if ((sign == 1 && res > INT32_MAX) || (sign == -1 && res > -(long long) INT32_MIN))
            return INT32_MAX;
        if (sign == -1) return -res;
        else return res;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // special case
        if (n == 0) return 1.0;
        // get the sign
        bool neg = false;
        if (n < 0) neg = true;
        n = abs(n);
        // calculate by recursive;
        double result;
        if (n % 2 == 0) {
            result = myPow(x, n/2) * myPow(x, n/2);
        } else {
            result = myPow(x, n/2) * myPow(x, n/2) * x;
        }
        if (neg) return 1/result;
        else return result;
    }
};

int main() {
    Solution s;
    return 0;
}

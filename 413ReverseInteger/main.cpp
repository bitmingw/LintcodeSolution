#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // special case
        if (n == 0) return 0;
        // get the sign
        bool neg = false;
        if (n < 0) neg = true;
        n = abs(n);
        // get each digit
        int digit;
        string revStr;
        while (n != 0) {
            digit = n % 10;
            n /= 10;
            revStr += string(1, digit + '0');
        }
        if (neg) revStr.insert(revStr.begin(), '-');
        // NOTE: avoid use atoi() since it doesn't provide error checking
        long int revLong = strtol(revStr.c_str(), NULL, 10);
        if (revLong > INT32_MAX || revLong < INT32_MIN) return 0;
        return static_cast<int>(revLong);
    }
};

int main() {
    Solution s;
    return 0;
}

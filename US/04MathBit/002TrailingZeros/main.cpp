#include <iostream>
using namespace std;

class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long numOf5 = 0;
        long long base = 5, x;
        while (true) {
            x = n / base;
            if (!x) break;
            numOf5 += x;
            base *= 5;
        }
        return numOf5;
    }
};

int main() {
    Solution s;
    return 0;
}

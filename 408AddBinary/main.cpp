#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        int aLen = a.size();
        int bLen = b.size();
        // special cases
        if (aLen == 0) return b;
        if (bLen == 0) return a;
        // append the prefix to make len(a) == len(b)
        if (aLen < bLen) {
            int diff = bLen - aLen;
            a = string(diff,'0') + a;
            aLen = bLen;
        } else if (aLen > bLen) {
            int diff = aLen - bLen;
            b = string(diff,'0') + b;
            bLen = aLen;
        }
        // add string from back to front
        string sum = "";
        int carry = 0;
        int localSum = 0;
        int i = aLen-1;
        while (i >= 0) {
            localSum = (a[i] - '0') + (b[i] - '0') + carry;
            if (localSum > 1) {
                localSum -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            sum = string(1, localSum + '0') + sum;
            --i;
        }
        if (carry) sum = string(1, '1') + sum;
        return sum;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
     int updateBits(int n, int m, int i, int j) {
        // special cases
        if (i == 0 && j == 31) return m;
        for (int k = i; k <= j; ++k) {
            copyBit(n, m, k, k-i);
        }
        return n;
    }

    void clearBit(int &num, int pos) {
        int mask = ~(1 << pos);
        num &= mask;
    }

    void setBit(int &num, int pos) {
        int mask = 1 << pos;
        num |= mask;
    }

    void copyBit(int &num, int ref, int pos, int ref_pos) {
        int mask = 1 << ref_pos;
        ref &= mask;
        if (ref == 0) clearBit(num, pos);
        else setBit(num, pos);
    }
};

int main() {
    Solution s;
    cout << s.updateBits(-521, 0, 31, 31) << endl;  // should be 2147483127
    return 0;
}

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
     // Note: this program should be correct,
     // but it fail the test on the web.
     // You should submit the alternative program.
     int updateBits(int n, int m, int i, int j) {
        // special cases
        if (i == 0 && j == 31) return m;
        int d = getHighBit(m);
        int m_part = m << i;
        int l_template = 0x7FFFFFFF >> (31 - i);
        int h_template = 0xFFFFFFFF << (i + d + 1);
        int l_part = n & l_template;
        int h_part = n & h_template;
        cout << h_part << " " << m_part << " " << l_part << endl;
        return h_part | m_part | l_part;
    }

    int getHighBit(int m) {
        int i = 31;
        int set_bit = 0x80000000;
        while (i >= 0) {
            if (m & set_bit) return i;
            --i;
            set_bit = set_bit >> 1;
        }
        return 0;  // although m == 0, it still has one significant bit
    }
};

int main() {
    Solution s;
    cout << s.updateBits(-521, 0, 31, 31) << endl;  // should be 2147483127
    return 0;
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        int sum = 0, pos = 0;
        int f = 0, g = 0, c = 0, s = 0;
        while (a || b || c) {
            f = a % 2;
            g = b % 2;
            s = f ^ g ^ c;
            c = (f & g) | (f & c) | (g & c);
            // Note: when left shift overflow, the shift is module
            if (pos < 32)
                sum |= (s << pos++);
            a = a >> 1;
            b = b >> 1;
            // Note: right shift in C++ is implement dependent
            // In this case the left bit is copied
            a &= 0x7FFFFFFF;
            b &= 0x7FFFFFFF;
        }
        return sum;
    }
};

int main() {
    Solution s;
    cout << s.aplusb(100, -100) << endl;  // should be 0
    return 0;
}

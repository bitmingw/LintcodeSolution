#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        // 1 <= n <= 3999
        // I, V, X, L(50), C(100), D(500), M(1000)
        int thousand = n / 1000;
        int hundred = (n % 1000) / 100;
        int ten = (n % 100) / 10;
        int one = (n % 10);
        string res;
        if (thousand) {
            for (int i = 1; i <= thousand; ++i) {
                res += "M";
            }
        }
        if (hundred) {
            if (hundred == 4) {
                res += "CD";
            } else if (hundred == 9) {
                res += "CM";
            } else if (hundred < 4) {
                for (int i = 1; i <= hundred; ++i) {
                    res += "C";
                }
            } else {
                res += "D";
                for (int i = 6; i <= hundred; ++i) {
                    res += "C";
                }
            }
        }
        if (ten) {
            if (ten == 4) {
                res += "XL";
            } else if (ten == 9) {
                res += "XC";
            } else if (ten < 4) {
                for (int i = 1; i <= ten; ++i) {
                    res += "X";
                }
            } else {
                res += "L";
                for (int i = 6; i <= ten; ++i) {
                    res += "X";
                }
            }
        }
        if (one) {
            if (one == 4) {
                res += "IV";
            } else if (one == 9) {
                res += "IX";
            } else if (one < 4) {
                for (int i = 1; i <= one; ++i) {
                    res += "I";
                }
            } else {
                res += "V";
                for (int i = 6; i <= one; ++i) {
                    res += "I";
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

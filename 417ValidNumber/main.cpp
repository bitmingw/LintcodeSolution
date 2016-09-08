#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        if (s.empty()) return false;
        // remove leading and trailing spaces
        int lspace = 0;
        while (s[lspace] == ' ') ++lspace;
        int tspace = s.size() - 1;
        while (s[tspace] == ' ') --tspace;
        if (lspace > tspace) return false;
        s = string(s.begin() + lspace, s.begin() + tspace + 1);

        bool has_sign = false, has_dot = false, has_num = false;
        bool has_pow = false, has_pow_sign = false;
        int num_part = -1;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // white space
            if (c == ' ') {
                return false;  // internal space
            } else if (c == '.') {
                if (has_dot) return false;  // multiple dot
                has_dot = true;
            } else if (c == 'e') {
                if (has_pow) return false;  // multiple pow
                has_pow = true;
            } else if (c == '+' || c == '-') {
                if (num_part == -1) {
                    if (has_sign) return false;  // multiple sign
                    has_sign = true;
                } else if (has_pow && s[i-1] == 'e') {
                    if (has_pow_sign) return false;  // multiple pow sign
                    has_pow_sign = true;
                } else {
                    return false;
                }
            } else if (c >= '0' && c <= '9') {
                if (!has_pow && !has_dot && num_part == -1) num_part = i;
                has_num = true;
                continue;
            } else {
                // unknown char
                return false;
            }
        }
        if (!has_num) return false;
        if (num_part == -1 && !has_dot) return false;
        if (has_dot && has_pow) return false;
        return true;
    }
};

int main() {
    Solution s;
    string data = "3";
    cout << s.isNumber(data) << endl;
    return 0;
}

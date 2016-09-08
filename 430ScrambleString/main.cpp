#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        int len = s1.size();
        if (len == 1) return s1[0] == s2[0];
        // simple check: if the sum of char matches
        int sum_s1 = 0, sum_s2 = 0;
        for (char c: s1) {
            sum_s1 += c - 'a';
        }
        for (char c: s2) {
            sum_s2 += c - 'a';
        }
        if (sum_s1 != sum_s2) return false;

        for (int i = 1; i < len; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, len-i), s2.substr(i, len-i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len-i, i)) && isScramble(s1.substr(i, len-i), s2.substr(0, len-i)))
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

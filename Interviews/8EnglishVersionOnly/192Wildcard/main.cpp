#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int len1 = strlen(s);
        int len2 = strlen(p);
        int p1 = 0, p2 = 0;
        while (p1 < len1 && p2 < len2) {
            if (p[p2] == '?') {
                ++p1;
                ++p2;
                continue;
            } else if (p[p2] != '*' && s[p1] == p[p2]) {
                ++p1;
                ++p2;
                continue;
            } else if (p[p2] != '*' && s[p1] != p[p2]) {
                return false;
            } else {
                // p[p2] == '*'
                if (p2+1 < len2 && p[p2+1] == '*') {
                    // remove duplicate *
                    ++p2;
                    continue;
                }
                bool match = false;
                for (int pn = p1; pn <= len1; ++pn) {
                    match = isMatch(s+pn, p+p2+1);
                    if (match) return true;
                }
                return false;
            }
        }
        if (p1 != len1-1 || p2 != len2-1) return false;
        else return true;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int slen = strlen(s);
        int plen = strlen(p);
        if (slen == 0) {
            // to match any empty string
            // p should be empty or .*.*
            if (plen == 0) return true;
            if (plen % 2 == 0) {
                for (int i = 1; i < plen; i += 2) {
                    if (p[i] != '*') return false;
                }
                return true;
            }
            return false;
        }
        // s is not empty, look at the cases of p
        if (plen == 0) return false;
        if (plen == 1) {
            if (s[0] == p[0] || p[0] == '.') return isMatch(s+1, p+1);
            else return false;
        }
        if (p[1] != '*') {
            if (s[0] == p[0] || p[0] == '.') return isMatch(s+1, p+1);
            else return false;
        } else {
            if (isMatch(s, p+2)) return true;
            if (p[0] == '.') {
                for (int i = 1; i <= slen; ++i) {
                    if (isMatch(s+i, p+2)) return true;
                }
            } else {
                for (int i = 1; i <= slen; ++i) {
                    if (s[i-1] == p[0]) {
                        if (isMatch(s+i, p+2)) return true;
                    } else {
                        break;
                    }
                }
            }
            return false;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

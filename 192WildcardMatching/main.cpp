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
        // write your code here
        int slen = strlen(s);
        int plen = strlen(p);
        int i = 0;
        int j = 0;
        int star = -1;
        int mark = -1;
        while (i < slen) {
            if (j < plen && (s[i] == p[j] || p[j] == '?')) {
                ++i;
                ++j;
            } else if (j < plen && p[j] == '*') {
                star = j++;
                mark = i;
            } else if (star != -1) {
                // has a star but not a matched char
                // move s forward
                j = star + 1;
                i = ++mark;
            } else {
                // no star and not a matched char
                return false;
            }
        }

        // remove redundant stars in p
        while (j < plen && p[j] == '*') ++j;
        return p[j] == '\0';
    }
};

int main() {
    Solution s;
    return 0;
}

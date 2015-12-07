#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if (!s.size()) return string();
        // allocate space for c char
        char *cs = new char[s.size()+1];
        for (int i = 0; i < s.size(); ++i) cs[i] = s[i];
        cs[s.size()] = 0;
        int s_begin, s_end, w_begin, w_end;
        int more_blanks = 0;
        s_begin = 0;
        s_end = s.size() - 1;
        // flip the whole string
        reverse(cs, s_begin, s_end);
        for (int i = 0; i < s.size(); ++i) {
            if (cs[i] == ' ') ++s_begin;
            else break;
        }
        for (int i = s.size() - 1; i > -1; --i) {
            if (cs[i] == ' ') --s_end;
            else break;
        }
        w_begin = s_begin;
        w_end = s_begin;
        while (w_end <= s_end) {
            while (cs[w_end] != 0 && cs[w_end] != ' ') ++w_end;
            reverse(cs, w_begin, w_end-1);
            if (more_blanks > 0) {
                move_ahead(cs, w_begin, w_end - w_begin, more_blanks);
                w_begin -= more_blanks;
                w_end -= more_blanks;
            }
            w_begin = w_end;
            more_blanks = -1;
            while (cs[w_begin] != 0 && cs[w_begin] == ' ') {
                ++w_begin;
                ++more_blanks;
            }
            if (cs[w_begin] == 0) break;
            w_end = w_begin;
        }
        return string(cs + s_begin, w_end - s_begin);
    }

    void reverse(char* s, int lo, int hi) {
        if (lo >= hi) return;
        char tmp;
        while (lo < hi) {
            tmp  = s[lo];
            s[lo] = s[hi];
            s[hi] = tmp;
            ++lo;
            --hi;
        }
        return;
    }

    void move_ahead(char* s, int lo, int len, int displace) {
        for (int i = 0; i < len; ++i) {
            s[lo - displace] = s[lo];
            ++lo;
        }
        for (int i = 0; i < displace; ++i) {
            s[--lo] = ' ';
        }
    }
};

int main() {
    Solution s;
    string test = "  the   sky is  blue ";
    string test2 = "world";
    cout << s.reverseWords(test) << " " << s.reverseWords(test).size() << endl;
    // should be "blue is sky the 15"
    cout << s.reverseWords(test2) << endl; // should be "world"
    return 0;
}

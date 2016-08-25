#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        if (s.empty()) return "";
        map<int, int> recordp;
        map<int, int> records;
        string sp;
        for (int i = 0; i < s.length() - 1; ++i) {
            sp += s[i];
            sp += ".";
        }
        sp += s[s.length() - 1];
        for (int i = 0; i < sp.length(); ++i) {
            recordp[i] = findLongestPalindrome(sp, i);
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            int len1 = numberOfChar(sp, 2*i, recordp[2*i]);
            int len2 = numberOfChar(sp, 2*i+1, recordp[2*i+1]);
            records[i] = max(len1, len2);
        }
        records[s.length() - 1] = numberOfChar(sp, 2*s.length()-1, recordp[2*s.length()-1]);
        int maxLen = -1;
        int maxPos = -1;
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->second > maxLen) {
                maxLen = it->second;
                maxPos = it->first;
            }
        }
        if (maxLen % 2 == 0) {
            return string(s.begin() + maxPos - maxLen/2 + 1, s.begin() + maxPos + maxLen/2 + 1);
        } else {
            return string(s.begin() + maxPos - maxLen/2, s.begin() + maxPos + maxLen/2 + 1);
        }
    }

    int findLongestPalindrome(string& s, int center) {
        int length = 1;
        int range = min(center, (int) s.length() - center - 1);
        for (int i = 1; i <= range; ++i) {
            if (s[center-i] == s[center+i]) length += 2;
            else break;
        }
        return length;
    }

    int numberOfChar(string& s, int center, int length) {
        int chars = 0;
        for (int i = center - length/2; i <= center + length/2; ++i) {
            if (s[i] != '.') ++chars;
        }
        return chars;
    }
};

int main() {
    Solution s;
    return 0;
}

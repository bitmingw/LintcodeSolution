#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        map<char, int> table;
        int start = 0;
        int end = 0;
        int max_length = 0;
        while (end < s.length()) {
            char c = s[end];
            if (table.find(c) == table.end()) {
                table[c] = end;
            } else {
                int i = start;
                for (; i <= table[c]; ++i) {
                    table.erase(table.find(s[i]));
                }
                start = i;  // note: to exit the loop i has been + 1
                table[c] = end;
            }
            if (end - start + 1 > max_length) {
                max_length = end - start + 1;
            }
            ++end;
        }
        return max_length;
    }
};

int main() {
    Solution s;
    return 0;
}

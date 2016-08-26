#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        if (s.empty()) return 0;
        int len = s.length();
        int begin_idx = -1, end_idx = len - 1;
        while (end_idx >= 0) {
            if (s[end_idx] == ' ') --end_idx;
            else break;
        }
        if (end_idx == -1) return 0;
        begin_idx = end_idx;
        while (begin_idx >= 0) {
            if (s[begin_idx] != ' ') --begin_idx;
            else break;
        }
        return end_idx - begin_idx;
    }
};

int main() {
    Solution s;
    return 0;
}

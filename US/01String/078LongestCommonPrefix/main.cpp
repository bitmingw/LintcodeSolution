#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        int short_len = shorestStrlen(strs);
        if (short_len == 0) return string();
        if (strs.size() == 1) return string(strs[0]);
        int common_len = 0;
        bool match_fail = false;
        for (int i = 0; i < short_len; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) {
                    match_fail = true;
                    break;
                }
            }
            if (match_fail) {
                common_len = i;
                break;
            }
        }
        if (!match_fail) common_len = short_len;
        return string(strs[0], 0, common_len);
    }

    int shorestStrlen(vector<string> &strs) {
        if (!strs.size()) {
            return 0;
        }
        int short_len = strs[0].size();
        for (int j = 1; j < strs.size(); ++j) {
            if (short_len > strs[j].size()) {
                short_len = strs[j].size();
            }
        }
        return short_len;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) {
            if (dict.empty() || dict.find("") != dict.end()) return true;
            else return false;
        }
        vector<bool> is_break(s.size()+1, false);
        is_break[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (string candidate: dict) {
                if (candidate.size() <= i && \
                    candidate == string(s.begin() + i - candidate.size(), s.begin() + i)) {
                    if (is_break[i - candidate.size()])
                        is_break[i] = is_break[i - candidate.size()];
                }
            }
        }
        return is_break[s.size()];
    }
};

int main() {
    Solution s;
    return 0;
}

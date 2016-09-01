#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> res;
        restoreIpAddresses(res, "", string(s), 4);
        return res;
    }

    void restoreIpAddresses(vector<string>& res, string applied, string left, int terms) {
        if (terms == 0) {
            if (left.empty()) {
                applied = string(applied.begin(), applied.end()-1);  // remove the dot
                res.push_back(applied);
                return;
            } else {
                return;
            }
        } else {
            int max_len = min(3, (int)left.size());
            for (int i = 1; i <= max_len; ++i) {
                string next = string(left.begin(), left.begin()+i);
                if (next[0] == '0' && next.size() > 1) continue;
                int next_num = stoi(next);
                if (0 <= next_num && next_num <= 255) {
                    next += ".";
                    restoreIpAddresses(res, applied + next, string(left.begin()+i, left.end()), terms-1);
                }
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

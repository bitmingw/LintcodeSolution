#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        deque<string> structure;
        if (path.empty()) return "/";
        string next_token;
        while (path.size()) {
            next_token = parse_next_token(path);
            if (next_token == "..") {
                if (structure.size())
                    structure.pop_back();
            } else if (next_token == "." || next_token == "") {
                continue;
            } else {
                structure.push_back(next_token);
            }
        }
        string res = "/";
        while (structure.size()) {
            next_token = structure.front();
            structure.pop_front();
            res += next_token;
            res += "/";
        }
        if (res.length() > 1) res = string(res.begin(), res.end()-1);
        return res;
    }

    string parse_next_token(string& path) {
        int begin_idx = 0, end_idx = 0;
        int len = path.length();
        while (begin_idx < len && path[begin_idx] == '/') ++begin_idx;
        end_idx = begin_idx;
        while (end_idx < len && path[end_idx] != '/') ++end_idx;
        string next_token = string(path.begin() + begin_idx, path.begin() + end_idx);
        path = string(path.begin() + end_idx, path.end());
        return next_token;
    }
};

int main() {
    Solution s;
    string test = "/a/./b/../../c/";
    cout << s.simplifyPath(test) << endl;  // should be "/c"
    return 0;
}

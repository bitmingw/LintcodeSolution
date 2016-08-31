#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        if (isPalindrome(s)) {
            res.push_back(vector<string>(1, s));
        }
        for (int i = 1; i < s.size(); ++i) {
            string sub_str = string(s.begin(), s.begin() + i);
            if (isPalindrome(sub_str)) {
                vector<vector<string>> sub_res = partition(string(s.begin() + i, s.end()));
                for (auto sol: sub_res) {
                    sol.insert(sol.begin(), sub_str);
                    res.push_back(sol);
                }
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        // empty is not palindrome
        if (s.empty()) return false;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

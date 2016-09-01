#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        int left = n, right = n;
        helper(res, "", left, right);
        return res;
    }

    void helper(vector<string>& res, string s, int left, int right) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            helper(res, s + string(1, '('), left-1, right);
        }
        if (right > 0) {
            helper(res, s + string(1, ')'), left, right-1);
        }
    }
};

int main() {
    Solution s;
    return 0;
}

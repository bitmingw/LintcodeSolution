#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        map<char, string> trans_table;
        trans_table['2'] = "abc";
        trans_table['3'] = "def";
        trans_table['4'] = "ghi";
        trans_table['5'] = "jkl";
        trans_table['6'] = "mno";
        trans_table['7'] = "pqrs";
        trans_table['8'] = "tuv";
        trans_table['9'] = "wxyz";

        vector<string> res;
        if (digits.empty()) return res;
        char c = digits[0];
        string to_add = trans_table[c];
        for (int i = 0; i < to_add.length(); ++i) {
            res.push_back(string(1, to_add[i]));
        }
        for (int i = 1; i < digits.length(); ++i) {
            c = digits[i];
            to_add = trans_table[c];
            vector<string> original(res.begin(), res.end());
            res.clear();
            for (int j = 0; j < to_add.length(); ++j) {
                for (string s: original) {
                    res.push_back(s + string(1, to_add[j]));
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

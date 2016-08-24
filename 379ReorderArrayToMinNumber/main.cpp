#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool str_comp(string s1, string s2) {
    // assume s1 and s2 are all digits and not empty
    int comp_len = min(s1.length(), s2.length());
    for (int i = 0; i < comp_len; ++i) {
        if (s1[i] < s2[i]) return true;
        else if (s1[i] > s2[i]) return false;
    }
    if (s1.length() < s2.length()) {
        if (s2[comp_len] < s2[comp_len-1]) {
            return false;
        } else {
            return true;
        }
    } else if (s1.length() > s2.length()) {
        if (s1[comp_len] < s1[comp_len-1]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        vector<string> digits;
        for (int n: nums) {
            digits.push_back(to_string(n));
        }
        sort(digits.begin(), digits.end(), str_comp);
        string res;
        for (string s: digits) {
            res += s;
        }
        // remove first 0s
        int i = 0;
        for (; i < res.size() - 1; ++i) {
            if (res[i] != '0') break;
        }
        return string(res.begin() + i, res.end());
    }
};

int main() {
    Solution s;
    return 0;
}

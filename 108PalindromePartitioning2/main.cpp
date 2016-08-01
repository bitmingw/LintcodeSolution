#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        if (s.length() == 0 || s.length() == 1) return 0;
        bool isPalid[s.length()][s.length()];
        for (int i = 0; i < s.length(); ++i) {
            isPalid[i][i] = true;
            if (i + 1 < s.length()) {
                isPalid[i][i+1] = (s[i] == s[i+1]);
            }
        }

        for (int i = s.length() - 2; i >= 0; --i) {
            for (int j = i + 2; j < s.length(); ++j) {
                isPalid[i][j] = isPalid[i+1][j-1] && (s[i] == s[j]);
            }
        }

        vector<int> cuts(s.length() + 1, 0);
        cuts[0] = -1;
        for (int i = 1; i < s.length() + 1; ++i) {
            cuts[i] = i - 1;
            for (int j = 0; j < i; ++j) {
                if (isPalid[j][i-1]) {
                    cuts[i] = min(cuts[i], cuts[j] + 1);
                }
            }
        }
        return cuts[s.length()];
    }
};

int main() {
    Solution s;
    cout << s.minCut("ab") << endl;  // should be 1
    cout << s.minCut("aa") << endl;  // should be 0
    cout << s.minCut("cdd") << endl;  // should be 1
    return 0;
}

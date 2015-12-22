#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i] == B[j]) {
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        if (j != B.size()) return false;
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "ABCD", s2 = "ACD", s3 = "AABC";
    cout << s.compareStrings(s1, s2) << " " << s.compareStrings(s1, s3) << endl;
    // should be 1 0
    return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (!source || !target) return -1;
        int source_len = strlen(source);
        int target_len = strlen(target);
        int idx = -1;
        cout << source_len << " " << target_len << endl;
        for (int i = 0; i <= source_len - target_len; ++i) {
            idx = i;
            for (int j = 0; j < target_len; ++j) {
                if (source[i+j] != target[j]) {
                    idx = -1;
                    break;
                }
            }
            if (idx > -1) return idx;
        }
        return -1;
    }
};

int main() {
    Solution s;
    char source[20] = "abcdabcdefg";
    char target[20] = "bcd";
    cout << s.strStr(source, target) << endl;  // should be 1
    char source2[5] = "";
    char target2[5] = "a";
    cout << s.strStr(source2, target2) << endl;  // should be -1
    return 0;
}

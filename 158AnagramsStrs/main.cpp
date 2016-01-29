#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return !strcmp(s.c_str(), t.c_str());
    }
};

int main() {
    Solution s;
    string s1 = "abcd", s2 = "dcab";
    cout << s.anagram(s1, s2) << endl;  // should be true
    return 0;
}

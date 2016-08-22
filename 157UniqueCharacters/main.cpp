#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        set<char> char_set;
        for (char c: str) {
            if (char_set.find(c) != char_set.end()) return false;
            else char_set.insert(c);
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

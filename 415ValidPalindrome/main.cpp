#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        if (s.empty()) return true;
        for (int i = 0; i < s.length(); ++i) {
            s[i] = tolower(s[i]);
        }
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            while (!isalnum(s[head])) ++head;
            while (!isalnum(s[tail])) --tail;
            if (head < tail) {
                if (s[head] != s[tail]) return false;
                else {
                    ++head;
                    --tail;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

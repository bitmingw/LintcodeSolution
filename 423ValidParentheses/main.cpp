#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char> charStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                charStack.push(s[i]);
            } else {
                if (charStack.empty()) return false;
                char last = charStack.top();
                if ((last == '(' && s[i] == ')') ||
                    (last == '[' && s[i] == ']') ||
                    (last == '{' && s[i] == '}')) {
                        charStack.pop();
                } else {
                    return false;
                }
            }
        }
        if (charStack.empty()) return true;
        else return false;
    }
};

int main() {
    Solution s;
    return 0;
}

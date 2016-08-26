#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        if (tokens.size() == 1) return stoi(tokens[0]);
        deque<int> reg;
        for (int i = 0; i < tokens.size(); ++i) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int op2 = reg.back();
                reg.pop_back();
                int op1 = reg.back();
                reg.pop_back();
                if (token == "+") reg.push_back(op1 + op2);
                if (token == "-") reg.push_back(op1 - op2);
                if (token == "*") reg.push_back(op1 * op2);
                if (token == "/") reg.push_back(op1 / op2);
            } else {
                reg.push_back(stoi(token));
            }
        }
        return reg.back();
    }
};

int main() {
    Solution s;
    return 0;
}

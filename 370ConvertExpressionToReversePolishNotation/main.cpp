#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> res;
        stack<string> ops;
        if (expression.empty()) return res;
        for (int i = 0; i < expression.size(); ++i) {
            string token = expression[i];
            if (token == "(") {
                ops.push(token);
            } else if (token == ")") {
                while (ops.size()) {
                    if (ops.top() != "(") {
                        res.push_back(ops.top());
                        ops.pop();
                    } else {
                        ops.pop();  // pop "("
                        break;
                    }
                }
            } else if (is_operator(token)) {
                while (ops.size() && get_priority(ops.top()) >= get_priority(token)) {
                    res.push_back(ops.top());
                    ops.pop();
                }
                ops.push(token);
            } else {
                // number
                res.push_back(token);
            }
        }
        while (ops.size()) {
            res.push_back(ops.top());
            ops.pop();
        }
        return res;
    }

    int get_priority(string str) {
        if (str == "(") return 0;
        if (str == "+" || str == "-") return 1;
        if (str == "*" || str == "/") return 2;
        return 3;
    }

    bool is_operator(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") return true;
        else return false;
    }
};


int main() {
    Solution s;
    return 0;
}

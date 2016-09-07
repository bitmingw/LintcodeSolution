#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        ExpressionTreeNode* node = NULL;
        vector<string> rpn = convertToRPN(expression);
        stack<ExpressionTreeNode*> st;
        for (int i = 0; i < rpn.size(); ++i) {
            if (!is_operator(rpn[i])) {
                node = new ExpressionTreeNode(rpn[i]);
                st.push(node);
            } else {
                node = new ExpressionTreeNode(rpn[i]);
                node->right = st.top();
                st.pop();
                node->left = st.top();
                st.pop();
                st.push(node);
            }
        }
        if (st.size()) return st.top();
        else return NULL;
    }

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

    int get_priority(string c) {
        if (c == "(") return 0;
        if (c == "+" || c == "-") return 1;
        if (c == "*" || c == "/") return 2;
        return 3;
    }

    bool is_operator(string c) {
        if (c == "+" || c == "-" || c == "*" || c == "/") return true;
        else return false;
    }
};


int main() {
    Solution s;
    return 0;
}

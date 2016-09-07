#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        if (expression.empty()) return 0;
        if (expression.size() == 1) return stoi(expression[0]);
        int lpos = find_left(expression);
        int rpos = find_right(expression);
        while (lpos != -1) {
            vector<string> inner(expression.begin()+lpos+1, expression.begin()+rpos);
            int val = evaluateExpression(inner);
            vector<string> copy;
            for (int i = 0; i < lpos; ++i) {
                copy.push_back(expression[i]);
            }
            copy.push_back(to_string(val));
            for (int i = rpos+1; i < expression.size(); ++i) {
                copy.push_back(expression[i]);
            }
            expression = copy;
            lpos = find_left(expression);
            rpos = find_right(expression);
        }
        // merge without parenthese
        while (expression.size() > 1) {
            if (expression.size() == 3) {
                return simple_eval(expression);
            } else {
                string op1 = expression[1];
                string op2 = expression[3];
                if ((op1 == "+" || op1 == "-") && (op2 == "*" || op2 == "/")) {
                    vector<string> inner(expression.begin() + 2, expression.begin() + 5);
                    int val = simple_eval(inner);
                    vector<string> copy;
                    copy.push_back(expression[0]);
                    copy.push_back(expression[1]);
                    copy.push_back(to_string(val));
                    for (int i = 5; i < expression.size(); ++i) {
                        copy.push_back(expression[i]);
                    }
                    expression = copy;
                } else {
                    vector<string> inner(expression.begin(), expression.begin() + 3);
                    int val = simple_eval(inner);
                    vector<string> copy;
                    copy.push_back(to_string(val));
                    for (int i = 3; i < expression.size(); ++i) {
                        copy.push_back(expression[i]);
                    }
                    expression = copy;
                }
            }
        }
        return stoi(expression[0]);
    }

    int find_left(vector<string>& expression) {
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == "(") return i;
        }
        return -1;
    }

    int find_right(vector<string>& expression) {
        int cnt = 0;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == "(") ++cnt;
            if (expression[i] == ")") {
                --cnt;
                if (cnt == 0) return i;
            }
        }
        return -1;
    }

    int simple_eval(vector<string>& expression) {
        int num1 = stoi(expression[0]);
        int num2 = stoi(expression[2]);
        string op = expression[1];
        if (op == "+") return num1 + num2;
        if (op == "-") return num1 - num2;
        if (op == "*") return num1 * num2;
        if (op == "/") return num1 / num2;
    }
};

int main() {
	Solution s;
	return 0;
}

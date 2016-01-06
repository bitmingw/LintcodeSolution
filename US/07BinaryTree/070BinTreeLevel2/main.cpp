#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> repr;
        stack<vector<int>> lineBuf;
        if (!root) return repr;
        vector<int> line;
        queue<TreeNode *> buf1, buf2;
        int flag = 1;
        TreeNode *cur;
        buf1.push(root);
        while (buf1.size() || buf2.size()) {
            if (flag == 1) {
                while (buf1.size()) {
                    cur = buf1.front();
                    line.push_back(cur->val);
                    if (cur->left) buf2.push(cur->left);
                    if (cur->right) buf2.push(cur->right);
                    buf1.pop();
                }
                lineBuf.push(line);
                line.clear();
                flag = 2;
            } else {
                while (buf2.size()) {
                    cur = buf2.front();
                    line.push_back(cur->val);
                    if (cur->left) buf1.push(cur->left);
                    if (cur->right) buf1.push(cur->right);
                    buf2.pop();
                }
                lineBuf.push(line);
                line.clear();
                flag = 1;
            }
        }
        while (lineBuf.size()) {
            repr.push_back(lineBuf.top());
            lineBuf.pop();
        }
        return repr;
    }
};

int main() {
    Solution s;
    return 0;
}

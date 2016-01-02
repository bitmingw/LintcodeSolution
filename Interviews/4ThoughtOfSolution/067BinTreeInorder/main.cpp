#include <vector>
#include <iostream>
using namespace std;


//Definition of TreeNode:
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
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> repr;
        vector<int> buf;
        if (!root) return repr;
        if (root->left) {
            buf = inorderTraversal(root->left);
            for (int i = 0; i < buf.size(); ++i) {
                repr.push_back(buf[i]);
            }
        }
        repr.push_back(root->val);
        if (root->right) {
            buf = inorderTraversal(root->right);
            for (int i = 0; i < buf.size(); ++i) {
                repr.push_back(buf[i]);
            }
        }
        return repr;
    }
};

int main() {
    Solution s;
    return 0;
}

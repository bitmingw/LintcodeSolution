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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> repr;
        vector<int> buf;
        if (!root) return repr;
        repr.push_back(root->val);
        if (root->left) {
            buf = preorderTraversal(root->left);
            for (int i = 0; i < buf.size(); ++i) {
                repr.push_back(buf[i]);
            }
        }
        if (root->right) {
            buf = preorderTraversal(root->right);
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

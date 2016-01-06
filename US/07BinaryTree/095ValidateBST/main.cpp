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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        bool leftValid = false, rightValid = false;
        if (!root->left) {
            leftValid = true;
        } else {
            leftValid = isValidBST(root->left) && (rightMost(root->left) < root->val);
        }
        if (!root->right) {
            rightValid = true;
        } else {
            rightValid = isValidBST(root->right) && (leftMost(root->right) > root->val);
        }
        return leftValid && rightValid;
    }

    int leftMost(TreeNode *root) {
        // assume root is not empty
        while (root->left)
            root = root->left;
        return root->val;
    }

    int rightMost(TreeNode *root) {
        // assume root is not empty
        while (root->right)
            root = root->right;
        return root->val;
    }
};

int main() {
    Solution s;
    return 0;
}

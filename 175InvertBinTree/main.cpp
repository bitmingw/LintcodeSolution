#include <iostream>
#include <vector>
#include <algorithm>
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
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (!root) return;
        TreeNode *tmp;
        // do the invert
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        // do recursively
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};


int main() {
    Solution s;
    return 0;
}

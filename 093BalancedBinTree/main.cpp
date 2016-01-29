#include <iostream>
#include <cmath>
#include <algorithm>
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) return false;
        return true;
    }

    int getHeight(TreeNode *root) {
        if (!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};

int main() {
    Solution s;
    return 0;
}

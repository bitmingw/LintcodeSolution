#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            if (root->val < 0) root->val = 0;
            return root->val;
        }
        // do post order traversal
        int lval = houseRobber3(root->left);
        int rval = houseRobber3(root->right);
        int lsubl = 0, lsubr = 0, rsubl = 0, rsubr = 0;
        if (root->left && root->left->left) lsubl = root->left->left->val;
        if (root->left && root->left->right) lsubr = root->left->right->val;
        if (root->right && root->right->left) rsubl = root->right->left->val;
        if (root->right && root->right->right) rsubr = root->right->right->val;
        int res = max(lval + rval, lsubl + lsubr + rsubl + rsubr + root->val);
        if (res < 0) res = 0;
        root->val = res;
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

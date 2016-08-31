#include <iostream>
#include <vector>
#include <cmath>

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
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        flatten(root, root->left, root->right);
    }

    void flatten(TreeNode* root, TreeNode* ltree, TreeNode* rtree) {
        if (ltree == NULL) {
            flatten(rtree);
        } else if (rtree == NULL) {
            flatten(ltree);
            root->right = ltree;
            root->left = NULL;
        } else {
            flatten(ltree);
            TreeNode* right_most = ltree;
            while (right_most->right) right_most = right_most->right;
            right_most->right = rtree;
            root->right = ltree;
            root->left = NULL;
            flatten(rtree);
        }
    }
};

int main() {
    Solution s;
    return 0;
}

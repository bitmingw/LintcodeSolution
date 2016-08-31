#include <iostream>
#include <vector>
#include <string>

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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> lres = binaryTreePaths(root->left);
        vector<string> rres = binaryTreePaths(root->right);
        if (lres.size()) {
            for (auto pre: lres) {
                res.push_back(to_string(root->val) + "->" + pre);
            }
        }
        if (rres.size()) {
            for (auto pre: rres) {
                res.push_back(to_string(root->val) + "->" + pre);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

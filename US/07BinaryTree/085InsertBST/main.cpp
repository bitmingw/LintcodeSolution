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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!root) return node;
        int val = node->val;
        TreeNode *cur = root;
        while (true) {
            if (cur->val > val) {
                if (cur->left) {
                    cur = cur->left;
                    continue;
                } else {
                    cur->left = node;
                    break;
                }
            }
            if (cur->val < val) {
                if (cur->right) {
                    cur = cur->right;
                    continue;
                } else {
                    cur->right = node;
                    break;
                }
            }
            // invalid input
            break;
        }
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}

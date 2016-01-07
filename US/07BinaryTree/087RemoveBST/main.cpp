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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (!root) return NULL;
        bool isLeft;
        bool isRoot = false;
        TreeNode *father;
        if (root->val == value) {
            father = new TreeNode(0);
            father->left = root;
            isLeft = true;
            isRoot = true;
        } else {
            father = root;
            while (father) {
                if (father->left && father->left->val == value) {
                    isLeft = true;
                    break;
                }
                if (father->right && father->right->val == value) {
                    isLeft = false;
                    break;
                }
                if (father->val > value && father->left) {
                    father = father->left;
                    continue;
                }
                if (father->val < value && father->right) {
                    father = father->right;
                    continue;
                }
                father = NULL;
            }
        }
        TreeNode *rm;
        if (father) {
            if (isLeft) {
                if (!father->left->left && !father->left->right) {
                    delete father->left;
                    father->left = NULL;
                } else if (father->left->left && !father->left->right) {
                    rm = father->left;
                    father->left = father->left->left;
                    delete rm;
                } else if (!father->left->left && father->left->right) {
                    rm = father->left;
                    father->left = father->left->right;
                    delete rm;
                } else {
                    int newVal = findMin(father->left->right);
                    father->left->val = newVal;
                    father->left->right = removeNode(father->left->right, newVal);
                }
            } else {
                if (!father->right->left && !father->right->right) {
                    delete father->right;
                    father->right = NULL;
                } else if (father->right->left && !father->right->right) {
                    rm = father->right;
                    father->right = father->right->left;
                    delete rm;
                } else if (!father->right->left && father->right->right) {
                    rm = father->right;
                    father->right = father->right->right;
                    delete rm;
                } else {
                    int newVal = findMin(father->right->right);
                    father->right->val = newVal;
                    father->right->right = removeNode(father->right->right, newVal);
                }
            }
            if (isRoot) {
                root = father->left;
                delete father;
            }
        }
        return root;
    }

    int findMin(TreeNode *root) {
        // assume not empty
        while (root->left)
            root = root->left;
        return root->val;
    }
};

int main() {
    Solution s;
    return 0;
}

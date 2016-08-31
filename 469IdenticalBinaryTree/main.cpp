#include <iostream>
#include <vector>

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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        else if ((!a && b) || (a && !b)) return false;
        else {
            if (a->val == b->val) {
                if (isIdentical(a->left, b->left) && isIdentical(a->right, b->right)) {
                    return true;
                }
                return false;
            }
            return false;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

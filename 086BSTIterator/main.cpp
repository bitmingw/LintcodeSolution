#include <iostream>
#include <stack>
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

class BSTIterator {
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        while (root) {
            trace.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return !trace.empty();
    }

    //@return: return next node
    TreeNode* next() {
        TreeNode *cur = trace.top();
        trace.pop();
        TreeNode *child = cur->right;
        while (child) {
            trace.push(child);
            child = child->left;
        }
        return cur;
    }

    stack<TreeNode *> trace;
};

int main() {
    Solution s;
    return 0;
}

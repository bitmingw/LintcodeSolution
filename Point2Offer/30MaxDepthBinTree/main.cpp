#include <string>
#include <cstring>
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    inline int max(int a, int b) {
        return (a > b) ? a : b;
    }
};

int main() {
    Solution s;
    cout << s.digitCounts(1, 12) << endl; // should be 5
    return 0;
}

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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> li;
        if (!root) return li;
        searchRange(root->left, li, k1, k2);
        if (root->val >= k1 && root->val <= k2) li.push_back(root->val);
        searchRange(root->right, li, k1, k2);
        return li;
    }

    void searchRange(TreeNode *root, vector<int> &vec, int k1, int k2) {
        if (!root) return;
        searchRange(root->left, vec, k1, k2);
        if (root->val >= k1 && root->val <= k2) vec.push_back(root->val);
        searchRange(root->right, vec, k1, k2);
    }
};

int main() {
    Solution s;
    return 0;
}

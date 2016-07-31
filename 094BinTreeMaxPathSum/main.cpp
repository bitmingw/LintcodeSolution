#include <iostream>
#include <algorithm>
#include <cstdint>

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
    int maxPathSum(TreeNode *root) {
        maxSum = INT32_MIN;
        sumSingle(root);
        return maxSum;
    }

    int sumSingle(TreeNode *root) {
        if (root == NULL) return 0;
        int sum = root->val;
        int lf = 0;
        int rt = 0;
        if (root->left)
            lf = sumSingle(root->left);
        if (root->right)
            rt = sumSingle(root->right);
        if (lf > 0)
            sum += lf;
        if (rt > 0)
            sum += rt;
        maxSum = max(maxSum, sum);
        return max(0, max(lf, rt)) + root->val;
    }

private:
    int maxSum;
};

int main() {
    Solution s;
    return 0;
}

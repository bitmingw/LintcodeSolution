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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        if (A.empty()) return NULL;
        int mi = A.size() / 2;
        TreeNode *root = new TreeNode(A[mi]);
        vector<int> left_arr = vector<int>(A.begin(), A.begin() + mi);
        vector<int> right_arr = vector<int>(A.begin() + mi + 1, A.end());
        root->left = sortedArrayToBST(left_arr);
        root->right = sortedArrayToBST(right_arr);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}

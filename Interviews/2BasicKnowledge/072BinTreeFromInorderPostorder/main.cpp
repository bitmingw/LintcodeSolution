#include <vector>
#include <iostream>
using namespace std;


// Definition of TreeNode:
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
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        if (!size) return NULL;
        int inPos = searchIn(inorder, postorder[size-1], 0, size-1);
        TreeNode *root = new TreeNode(inorder[inPos]);
        root->left = buildTree(inorder, postorder, 0, 0, inPos);
        root->right = buildTree(inorder, postorder, inPos+1, inPos, size-inPos-1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int postStart, int len) {
        if (!len) return NULL;
        int inPos = searchIn(inorder, postorder[postStart+len-1], inStart, inStart+len-1);
        TreeNode *root = new TreeNode(inorder[inPos]);
        root->left = buildTree(inorder, postorder, inStart, postStart, inPos-inStart);
        root->right = buildTree(inorder, postorder, inPos+1, postStart+inPos-inStart, inStart+len-inPos-1);
        return root;
    }

    int searchIn(vector<int> &inorder, int target, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == target) return i;
        }
        return -1;  // should not happen
    }
};

int main() {
    Solution s;
    return 0;
}

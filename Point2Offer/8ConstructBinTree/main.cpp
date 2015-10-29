#include <string>
#include <cstring>
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() == 0 || preorder.size() != inorder.size()) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int pivotInIdx = findPivotInorder(preorder[0], inorder, 0, inorder.size()-1);
        root->left = buildTreeRecur(preorder, inorder, 1, pivotInIdx, 0, pivotInIdx-1);
        root->right = buildTreeRecur(preorder, inorder, \
            pivotInIdx+1, preorder.size()-1, pivotInIdx+1, inorder.size()-1);
        return root;
    }
    
    TreeNode *buildTreeRecur(vector<int> &preorder, vector<int> &inorder,
                             int preStart, int preEnd, int inStart, int inEnd) {
        // when empty
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        // when only one node
        if (preStart == preEnd && inStart == inEnd) {
            return new TreeNode(preorder[preStart]);
        } else {
            TreeNode *node = new TreeNode(preorder[preStart]);
            int pivotInIdx = findPivotInorder(preorder[preStart], inorder, inStart, inEnd);
            int leftSize = pivotInIdx - inStart;
            node->left = buildTreeRecur(preorder, inorder, \
                preStart+1, preStart+leftSize, inStart, inStart+leftSize-1);
            node->right = buildTreeRecur(preorder, inorder, \
                preStart+leftSize+1, preEnd, inStart+leftSize+1, inEnd);
            return node;
        }
    }
    
    int findPivotInorder(int number, vector<int> &inorder, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == number) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> pre;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(3);
    pre.push_back(4);
    pre.push_back(5);
    vector<int> in;
    in.push_back(5);
    in.push_back(4);
    in.push_back(3);
    in.push_back(2);
    in.push_back(1);
    
    Solution s;
    cout << s.buildTree(pre, in)->val << endl;
    return 0;
}

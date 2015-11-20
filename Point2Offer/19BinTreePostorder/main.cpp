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
     * @return: Postorder in vector which contains node values.
     */
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> seq = vector<int>();
        if (root) {
            postorderTraversalRecur(root->left, seq);
            postorderTraversalRecur(root->right, seq);
            seq.push_back(root->val);
        }
        return seq;
    }
    
    void postorderTraversalRecur(TreeNode *root, vector<int>& vec) {
        if (root == NULL) {
            return;
        }
        postorderTraversalRecur(root->left, vec);
        postorderTraversalRecur(root->right, vec);
        vec.push_back(root->val);
    }
};


int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    Solution s;
    vector<int> result = s.postorderTraversal(root);
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

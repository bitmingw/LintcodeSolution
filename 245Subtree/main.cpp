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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) {
            return true;
        } else if (T1 == NULL) { // T2 is not NULL
            return false;
        } else if (T1->val == T2->val) {
            return isIdentical(T1, T2);
        } else {
            return isSubtree(T1->left, T2) | isSubtree(T1->right, T2);
        }
    }
    
    bool isIdentical(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) {
            return true;
        } else if (T1 == NULL || T2 == NULL) {
            return false;
        } else {
            if (T1->val != T2->val) {
                return false;
            } else {
                return isIdentical(T1->left, T2->left) & isIdentical(T1->right, T2->right);
            }
        }
    }
};
 

int main() {
	TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    
    TreeNode *h2 = new TreeNode(3);
    h2->left = new TreeNode(4);
    
    Solution s;
    cout << s.isSubtree(head, h2) << endl;
    return 0;
}

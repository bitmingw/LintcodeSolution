#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> traversal = vector<vector<int>>();
        vector<int> thisLevel = vector<int>();
        queue<TreeNode*> q1 = queue<TreeNode*>();
        queue<TreeNode*> q2 = queue<TreeNode*>();
        TreeNode *curNode = NULL;

        if (root == NULL) {
            return traversal;
        }
        
        q1.push(root);
        int flag = 1;
        while (q1.size() || q2.size()) {
            if (flag == 1) {
                while (q1.size()) {
                    curNode = q1.front();
                    if (curNode->left) q2.push(curNode->left);
                    if (curNode->right) q2.push(curNode->right);
                    thisLevel.push_back(curNode->val);
                    q1.pop();
                }
                flag = 2;
                traversal.push_back(vector<int>(thisLevel));
                thisLevel.clear();
            } else {
                while (q2.size()) {
                    curNode = q2.front();
                    if (curNode->left) q1.push(curNode->left);
                    if (curNode->right) q1.push(curNode->right);
                    thisLevel.push_back(curNode->val);
                    q2.pop();
                }
                flag = 1;
                traversal.push_back(vector<int>(thisLevel));
                thisLevel.clear();
            }
        }
    }
};


int main() {
    return 0;
}

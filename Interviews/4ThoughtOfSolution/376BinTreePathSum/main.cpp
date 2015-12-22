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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector<int>> pathSum = vector<vector<int>>();
        preTraversal(root, pathSum, vector<int>(), 0, target);
        return pathSum;
    }

    void preTraversal(TreeNode *root, vector<vector<int>>& collection,
            vector<int> path, int sum, int target) {
        if (!root) return;
        path.push_back(root->val);
        sum += root->val;
        if (sum == target) {
            vector<int> foundPath = vector<int>(path); // copy the corrent path
            collection.push_back(foundPath);
        }
        preTraversal(root->left, collection, path, sum, target);
        preTraversal(root->right, collection, path, sum, target);
    }
};



int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(4);
    Solution s;
    vector<vector<int>> result = s.binaryTreePathSum(root, 5);
    cout << result.size() << " " << result[0].size() << " " << result[1].size() << endl;
    // test result should be "2 3 2"
    return 0;
}

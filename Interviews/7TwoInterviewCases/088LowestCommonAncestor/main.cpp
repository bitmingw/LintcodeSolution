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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // assume all the nodes are not NULL
        vector<TreeNode*> pathA, pathB; // path from node to root
        findPath(pathA, root, A);
        findPath(pathB, root, B);
        return findLCA(pathA, pathB);
    }
    
    bool findPath(vector<TreeNode*> &path, TreeNode *root, TreeNode *node) {
        if (root == NULL || node == NULL) return false;
        if (root == node) {
            path.push_back(root);
            return true;
        }
        if (findPath(path, root->left, node) || findPath(path, root->right, node)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode *findLCA(vector<TreeNode*> pathA, vector<TreeNode*> pathB) {
        int idxA = -1, idxB = -1;
        for (int i = 0; i < pathA.size() && i < pathB.size(); ++i) {
            idxA = pathA.size() - i - 1;
            idxB = pathB.size() - i - 1;
            if (pathA[idxA] != pathB[idxB]) break;
        }
        if (idxA == -1) return NULL;
        if (pathA[idxA] == pathB[idxB]) return pathA[idxA];
        else return pathA[idxA+1];
    }
};

int main() {
    Solution s;
    return 0;
}

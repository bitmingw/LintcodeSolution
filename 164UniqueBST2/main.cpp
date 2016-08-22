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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> all_trees;
        if (n == 0) {
            all_trees.push_back(NULL);
            return all_trees;
        }
        vector<int> seq;
        for (int i = 1; i <= n; ++i) {
            seq.push_back(i);
        }
        all_trees = generateTrees(seq);
        return all_trees;
    }
    
    vector<TreeNode*> generateTrees(vector<int> seq) {
        // assume seq is not empty
        vector<TreeNode*> trees;
        for (int i = 0; i < seq.size(); ++i) {
            vector<int> left_seq(seq.begin(), seq.begin() + i);
            vector<int> right_seq(seq.begin() + i + 1, seq.end());
            if (left_seq.empty() && right_seq.empty()) {
                trees.push_back(new TreeNode(seq[i]));
            }
            if (left_seq.empty()) {
                vector<TreeNode*> right_trees = generateTrees(right_seq);
                int n = right_trees.size();
                for (int k = 0; k < n; ++k) {
                    TreeNode* root = new TreeNode(seq[i]);
                    root->right = copyTree(right_trees[k]);
                    trees.push_back(root);
                }
            } else if (right_seq.empty()) {
                vector<TreeNode*> left_trees = generateTrees(left_seq);
                int m = left_trees.size();
                for (int j = 0; j < m; ++j) {
                    TreeNode* root = new TreeNode(seq[i]);
                    root->left = copyTree(left_trees[j]);
                    trees.push_back(root);
                }
            } else {
                vector<TreeNode*> left_trees = generateTrees(left_seq);
                vector<TreeNode*> right_trees = generateTrees(right_seq);
                int m = left_trees.size();
                int n = right_trees.size();
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < n; ++k) {
                        TreeNode* root = new TreeNode(seq[i]);
                        root->left = copyTree(left_trees[j]);
                        root->right = copyTree(right_trees[k]);
                        trees.push_back(root);
                    }
                }
            }
        }
        return trees;
    }
    
    TreeNode* copyTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = copyTree(root->left);
        new_root->right = copyTree(root->right);
        return new_root;
    }
};

int main() {
    Solution s;
    return 0;
}

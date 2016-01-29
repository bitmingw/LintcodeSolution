#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> traversal;
        vector<int> level;
        if (!root) return traversal;
        deque<TreeNode *> queue;
        queue.push_back(root);
        queue.push_back(NULL);
        while (queue.size()) {
            if (queue.front() != NULL) {
                level.push_back(queue.front()->val);
                if (queue.front()->left) queue.push_back(queue.front()->left);
                if (queue.front()->right) queue.push_back(queue.front()->right);
                queue.pop_front();
            } else {
                traversal.push_back(level);
                level.erase(level.begin(), level.end());
                queue.pop_front();
                if (queue.size())
                    queue.push_back(NULL);
            }
        }
        // do zigzag
        for (int i = 1; i < traversal.size(); i+=2) {
            reverseVec(traversal[i]);
        }
        return traversal;
    }
    
    void reverseVec(vector<int>& vec) {
        int i = 0, j = vec.size()-1;
        int tmp;
        while (i < j) {
            tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            ++i;
            --j;
        }
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> traversal = s.zigzagLevelOrder(root);
    for (int i = 0; i < traversal.size(); ++i) {
        for (int j = 0; j < traversal[i].size(); ++j) {
            cout << traversal[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

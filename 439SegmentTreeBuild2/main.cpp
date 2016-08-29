#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if (A.empty()) return NULL;
        int n = A.size();
        SegmentTreeNode* root = build(A, 0, n-1);
        if (root->left) root->max = max(root->left->max, root->right->max);
        return root;
    }

    SegmentTreeNode* build(vector<int>& A, int start, int end) {
        SegmentTreeNode* root = new SegmentTreeNode(start, end, 0);
        if (start == end) root->max = A[start];
        else {
            int le = (start + end) / 2;
            int rs = le + 1;
            root->left = build(A, start, le);
            root->right = build(A, rs, end);
            root->max = max(root->left->max, root->right->max);
        }
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}

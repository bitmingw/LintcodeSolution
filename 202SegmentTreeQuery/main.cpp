#include <iostream>
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
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // assert start <= end, start >= root->start, end <= root->end
        // for leaf node, return the result
        if ((!root->left) && (!root->right)) {
            return root->max;
        }
        // for exact match, return the result
        if (root->start == start && root->end == end) {
            return root->max;
        }
        // for others, get the left and right range
        int le = root->left->end;
        int rs = root->right->start;
        if (end <= le) {
            return query(root->left, start, end);
        } else if (start >= rs) {
            return query(root->right, start, end);
        } else {
            return max(query(root->left, start, le), query(root->right, rs, end));
        }
        return 0;  // will not go here
    }
};

int main() {
    Solution s;
    return 0;
}

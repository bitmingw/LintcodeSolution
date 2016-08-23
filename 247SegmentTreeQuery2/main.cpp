#include <iostream>

using namespace std;

class SegmentTreeNode {
public:
    int start, end, count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // need to have start <= end, root->start <= start, root->end >= end
        if (!root) return 0;
        if (start > end || start > root->end || end < root->start) return 0;
        if (start < root->start) start = root->start;
        if (end > root->end) end = root->end;

        if (root->start == start && root->end == end) {
            return root->count;
        }
        int le = root->left->end;
        int rs = root->right->start;
        if (end <= le) {
            return query(root->left, start, end);
        } else if (start >= rs) {
            return query(root->right, start, end);
        } else {
            return query(root->left, start, le) + query(root->right, rs, end);
        }
    }
};

int main() {
    Solution s;
    return 0;
}

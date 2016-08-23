#include <iostream>

using namespace std;

class SegmentTreeNode {
public:
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) return NULL;
        if (start == end) {
            return new SegmentTreeNode(start, end);
        } else {
            SegmentTreeNode* root = new SegmentTreeNode(start, end);
            root->left = build(start, (start+end)/2);
            root->right = build((start+end)/2+1, end);
            return root;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

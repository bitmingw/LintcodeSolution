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
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // assume index >= root->start and index <= root->end
        // change the leaf node
        if (root->start == root->end) {
            root->max = value;
            return;
        }
        // for internal node, pass down and update the max value
        int le = root->left->end;
        if (index <= le) {
            modify(root->left, index, value);
        } else {
            modify(root->right, index, value);
        }
        root->max = max(root->left->max, root->right->max);
    }
};

int main() {
    Solution s;
    return 0;
}

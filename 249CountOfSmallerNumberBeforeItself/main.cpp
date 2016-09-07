#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SegmentTree {
public:
    SegmentTree(int b, int e, int c)
        : begin(b), end(e), count(c) {}
    int begin;
    int end;
    int count;
    SegmentTree* left;
    SegmentTree* right; 
};

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> res;
        if (A.empty()) return res;
        SegmentTree* root = buildSeg(0, 20000);  // assume max number is 20000
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > 0) {
                res.push_back(query(root, 0, A[i]-1));
            } else {
                res.push_back(0);
            }
            modify(root, A[i]);
        }
        return res;
    }

    SegmentTree* buildSeg(int begin, int end) {
        SegmentTree* node = NULL;
        if (begin == end) {
            node = new SegmentTree(begin, end, 0);
        } else {
            int le = (begin + end) / 2;
            int rb = le + 1;
            node = new SegmentTree(begin, end, 0);
            node->left = buildSeg(begin, le);
            node->right = buildSeg(rb, end);
            node->count = node->left->count + node->right->count;
        }
        return node;
    }

    int query(SegmentTree* root, int begin, int end) {
        // base case
        if (root->begin == begin && root->end == end) return root->count;
        // divide the problem
        int le = (root->begin + root->end) / 2;
        int sum = 0;
        if (end <= le) {
            sum = query(root->left, begin, end);
        } else if (begin >= le + 1) {
            sum = query(root->right, begin, end);
        } else {
            sum = query(root->left, begin, le) + query(root->right, le+1, end);
        }
        return sum;
    }

    void modify(SegmentTree* root, int index) {
        if (root->begin == index && root->end == index) {
            root->count++;
            return;
        }
        int le = (root->begin + root->end) / 2;
        if (index <= le) modify(root->left, index);
        else modify(root->right, index);
        root->count = root->left->count + root->right->count;
    }
};

int main() {
    Solution s;
    return 0;
}

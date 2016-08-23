#include <iostream>
#include <algorithm>
#include <cstdint>

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

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // first build the segment tree for A
        SegmentTreeNode* root = build_seg_tree(A, 0, A.size()-1);
        vector<int> ans;
        for (auto q: queries) {
            ans.push_back(find_min_value(root, q.start, q.end));
        }
        return ans;
    }

    SegmentTreeNode* build_seg_tree(vector<int> &A, int start_idx, int end_idx) {
        if (start_idx == end_idx) {
            return new SegmentTreeNode(start_idx, end_idx, A[start_idx]);
        }
        SegmentTreeNode* root = new SegmentTreeNode(start_idx, end_idx, INT32_MAX);
        int left_idx = (start_idx + end_idx) / 2;
        int right_idx = (start_idx + end_idx) / 2 + 1;
        root->left = build_seg_tree(A, start_idx, left_idx);
        root->right = build_seg_tree(A, right_idx, end_idx);
        // should be root->min, due to the limitation we could only use root->max
        root->max = min(root->left->max, root->right->max);
        return root;
    }

    int find_min_value(SegmentTreeNode* root, int start_idx, int end_idx) {
        if (root->start == start_idx && root->end == end_idx) {
            return root->max;
        }
        int le = root->left->end;
        int rs = root->right->start;
        if (end_idx <= le) {
            return find_min_value(root->left, start_idx, end_idx);
        } else if (start_idx >= rs) {
            return find_min_value(root->right, start_idx, end_idx);
        } else {
            return min(find_min_value(root->left, start_idx, le), find_min_value(root->right, rs, end_idx));
        }
        return 0;  // should not go here
    }
};

int main() {
    Solution s;
    return 0;
}

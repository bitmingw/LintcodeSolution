#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

class SegmentTree {
public:
    int start, end;
    long long sum;
    SegmentTree *left, *right;
    SegmentTree(int start, int end, long long sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        if (A.empty()) root = NULL;
        else root = build(A, 0, A.size()-1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        if (start < 0) start = 0;
        if (end > root->end) end = root->end;
        // assume start <= end
        return query(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // assume index is valid
        modify(root, index, value);
    }

    SegmentTree* build(vector<int>& A, int start, int end) {
        SegmentTree* root = new SegmentTree(start, end, INT32_MIN);
        if (start == end) {
            root->sum = A[start];
        } else {
            int le = (start + end) / 2;
            int rs = le + 1;
            root->left = build(A, start, le);
            root->right = build(A, rs, end);
            root->sum = root->left->sum + root->right->sum;
        }
        return root;
    }

    long long query(SegmentTree* pos, int start, int end) {
        // assume start <= end
        if (start == pos->start && end == pos->end) {
            return pos->sum;
        } else {
            int le = pos->left->end;
            int rs = le + 1;
            if (end <= le) return query(pos->left, start, end);
            else if (start >= rs) return query(pos->right, start, end);
            else return query(pos->left, start, le) + query(pos->right, rs, end);
        }
    }

    void modify(SegmentTree* pos, int index, int value) {
        if (pos->start == pos->end && pos->start == index) {
            pos->sum = value;
        } else {
            int le = pos->left->end;
            if (index <= le) {
                modify(pos->left, index, value);
                pos->sum = pos->left->sum + pos->right->sum;
            } else {
                modify(pos->right, index, value);
                pos->sum = pos->left->sum + pos->right->sum;
            }
        }
    }

    SegmentTree* root;
};

int main() {
    return 0;
}

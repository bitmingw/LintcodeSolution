#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        for (int i = A.size()-1; i >= 0; --i) {
            heapify(A, i);
        }
    }

    void heapify(vector<int>& A, int pos) {
        int left = pos*2 + 1;
        int right = pos*2 + 2;
        int minPos = pos;
        int minNum = A[pos];
        if (left < A.size() && A[left] < minNum) {
            minPos = left;
            minNum = A[left];
        }
        if (right < A.size() && A[right] < minNum) {
            minPos = right;
            minNum = A[right];
        }
        if (minPos == left) {
            swap(A, pos, left);
            heapify(A, left);
        }
        if (minPos == right) {
            swap(A, pos, right);
            heapify(A, right);
        }
    }

    void swap(vector<int>& A, int pos1, int pos2) {
        int temp = A[pos1];
        A[pos1] = A[pos2];
        A[pos2] = temp;
    }
};

int main() {
    Solution s;
    return 0;
}

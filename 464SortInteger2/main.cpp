#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        if (A.size() < 2) return;
        quickSort(A, 0, A.size()-1);
    }

    void quickSort(vector<int>& A, int lo, int hi) {
        if (lo >= hi) return;
        int begin = lo;
        int end = hi;
        int pivot = A[lo++];
        while (lo <= hi) {
            while (A[lo] < pivot) ++lo;
            while (A[hi] > pivot) --hi;
            if (lo >= hi) break;
            else {
                int tmp = A[lo];
                A[lo] = A[hi];
                A[hi] = tmp;
                ++lo;
                --hi;
            }
        }
        A[begin] = A[hi];
        A[hi] = pivot;
        quickSort(A, begin, hi-1);
        quickSort(A, lo, end);
    }
};

int main() {
    Solution s;
    return 0;
}

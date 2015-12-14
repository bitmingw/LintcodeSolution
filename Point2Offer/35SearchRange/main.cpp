#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int leftIdx = searchLeft(A, target, 0, A.size()-1);
        int rightIdx = searchRight(A, target, 0, A.size()-1);
        vector<int> range;
        range.push_back(leftIdx);
        range.push_back(rightIdx);
        return range;
    }
    
    int searchLeft(vector<int> &A, int target, int lo, int hi) {
        if (lo > hi) return -1;
        int mi = (lo + hi) / 2;
        if (A[mi] == target && (mi == 0 || A[mi-1] != target))
            return mi;
        else if (A[mi] >= target)
            return searchLeft(A, target, lo, mi - 1);
        else
            return searchLeft(A, target, mi + 1, hi);
    }
    
    int searchRight(vector<int> &A, int target, int lo, int hi) {
        if (lo > hi) return -1;
        int mi = (lo + hi) / 2;
        if (A[mi] == target && (mi == A.size()-1 || A[mi+1] != target))
            return mi;
        else if (A[mi] <= target)
            return searchRight(A, target, mi + 1, hi);
        else
            return searchRight(A, target, lo, mi - 1);
    }
};

int main() {
    Solution s;
    int vec[] = {5, 7, 7, 8, 8, 10};
    vector<int> vec2(vec, vec+6);
    vector<int> range = s.searchRange(vec2, 8);
    cout << range[0] << " " << range[1] << endl;  // should be 3 4
    vector<int> range2 = s.searchRange(vec2, 10);
    cout << range2[0] << " " << range2[1] << endl;  // should be 5 5
    return 0;
}

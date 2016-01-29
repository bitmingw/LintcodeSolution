#include <iostream>
#include <vector>
using namespace std;

class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        if (!A.size()) return 0;
        int lo = 0, hi = A.size()-1;
        int mi;
        while (lo <= hi) {
            mi = (lo + hi) / 2;
            if (A[mi] == target) return mi;
            if (A[mi] < target) lo = mi + 1;
            else hi = mi - 1;
        }
        return lo;
    }
};

int main() {
    Solution s;
    int arr[] = {1, 3, 5, 6};
    vector<int> vec(arr, arr+4);
    cout << s.searchInsert(vec, 5) << s.searchInsert(vec, 2) << s.searchInsert(vec, 7) << s.searchInsert(vec, 0) << endl;
    // should be 2140
	return 0;
}

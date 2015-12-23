#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        if (!array.size()) return -1;
        int lo = 0, hi = array.size()-1;
        int mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (array[mi] == target && (mi == 0 || array[mi-1] != target)) {
                return mi;
            }
            if (array[mi] >= target) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    int arr[] = {1, 2, 3, 3, 4, 5, 10};
    vector<int> vec(arr, arr+7);
    cout << s.binarySearch(vec, 3) << endl;  // should be 2
	return 0;
}

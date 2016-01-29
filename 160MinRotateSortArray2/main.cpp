#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // assume the vector is not empty
        int size = num.size();
        if (size == 1) return num[0];
        if (num[size-1] <= num[0]) {
            // rotated
            int lo = 0, hi = size - 1;
            int mi = lo + (hi - lo) / 2;
            return min(min(findMin(num, lo, mi-1), findMin(num, mi+1, hi)), num[mi]);
        } else {
            // normal
            return num[0];
        }
    }

    int findMin(vector<int> &num, int lo, int hi) {
        if (lo >= hi) return num[lo];
        int mi = lo + (hi - lo) / 2;
        return min(min(findMin(num, lo, mi-1), findMin(num, mi+1, hi)), num[mi]);
    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);

    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        if (!nums.size()) return 0;
        int lo = 0;
        int hi = nums.size()-1;
        while (true) {
            while (nums[lo] < k && lo <= hi) ++lo;
            while (nums[hi] >= k && lo <= hi) --hi;
            if (lo > hi) break;
            else {
                exch(nums, lo, hi);
                ++lo;
                --hi;
            }
        }
        return lo;
    }

    void exch(vector<int> &nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
    }
};

int main() {
    Solution s;
    int arr[] = {3, 2, 2, 1};
    vector<int> vec(arr, arr+4);
    cout << s.partitionArray(vec, 2) << endl;  // should be 1
    cout << s.partitionArray(vec, 10) << endl;  // should be 4
    return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        if (nums.size() < 2) return 0;

        // Generate a negative array
        vector<int> neg_nums(nums.begin(), nums.end());
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            *it = -(*it);
        }

        // Call maxSubArrays
        return max(maxSubArrays(nums, neg_nums), maxSubArrays(neg_nums, nums));
    }

    int maxSubArrays(vector<int>& nums, vector<int>& neg_nums) {
        int len = nums.size();
        vector<int> local(len, INT32_MIN);
        vector<int> global(len, INT32_MIN);
        vector<int> neg_local(len, INT32_MIN);

        local[0] = nums[0];
        global[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            local[i] = max(local[i-1] + nums[i], nums[i]);
            global[i] = max(global[i-1], local[i]);
        }
        neg_local[len-1] = neg_nums[len-1];
        for (int i = len-2; i >= 0; --i) {
            neg_local[i] = max(neg_local[i+1] + neg_nums[i], neg_nums[i]);
        }
        int max_val = INT32_MIN;
        for (int i = 0; i < len-1; ++i) {
            if (global[i] + neg_local[i+1] > max_val)
                max_val = global[i] + neg_local[i+1];
        }
        return max_val;
    }
};

int main() {
    Solution s;
    vector<int> data = {1, 2, -3, 1};
    cout << s.maxDiffSubArrays(data) << endl;  // should be 6
    return 0;
}

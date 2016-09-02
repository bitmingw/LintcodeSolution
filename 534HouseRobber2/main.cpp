#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int len = nums.size();
        int ans;
        vector<int> sum_val(len, 0);
        sum_val[0] = nums[0];
        sum_val[1] = nums[0];
        if (len > 2) {
            for (int i = 2; i + 1 < len; ++i) {
                sum_val[i] = max(sum_val[i-1], sum_val[i-2] + nums[i]);
            }
            sum_val[len-1] = sum_val[len-2];
        }
        ans = sum_val[len-1];

        sum_val = vector<int>(len, 0);
        sum_val[0] = 0;
        sum_val[1] = nums[1];
        if (len > 2) {
            for (int i = 2; i + 1 < len; ++i) {
                sum_val[i] = max(sum_val[i-1], sum_val[i-2] + nums[i]);
            }
            sum_val[len-1] = max(sum_val[len-2], sum_val[len-3] + nums[len-1]);
        }
        return max(ans, sum_val[len-1]);
    }
};

int main() {
    Solution s;
    return 0;
}

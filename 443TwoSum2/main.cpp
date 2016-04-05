#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int cnt = 0;
        while (i < j) {
            if (nums[i] + nums[j] <= target) {
                ++i;
            } else {
                cnt += j - i;
                --j;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    return 0;
}

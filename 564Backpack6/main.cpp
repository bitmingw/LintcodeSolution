#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        if (target < nums[0]) return 0;
        vector<int> cases(target+1, 0);
        cases[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int n: nums) {
                if (i >= n) {
                    cases[i] += cases[i-n];
                }
            }
        }
        return cases[target];
    }
};

int main() {
    Solution s;
    return 0;
}

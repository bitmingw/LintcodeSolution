#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 2) return;
        int n = nums.size();
        int reverse_idx = -1;
        int critical_num = 0;
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                reverse_idx = i;
                critical_num = nums[reverse_idx];
                break;
            }
        }
        if (reverse_idx == -1) {
            sort(nums.begin(), nums.end());
        } else {
            sort(nums.begin() + reverse_idx, nums.end());
            for (int i = reverse_idx; i < n; ++i) {
                if (nums[i] > critical_num) {
                    int tmp = nums[reverse_idx];
                    nums[reverse_idx] = nums[i];
                    nums[i] = tmp;
                    sort(nums.begin() + reverse_idx + 1, nums.end());
                    break;
                }
            }
        }
        return;
    }
};

int main() {
    Solution s;
    return 0;
}

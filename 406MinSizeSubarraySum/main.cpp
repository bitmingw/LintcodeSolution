#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        if (nums.empty()) return -1;
        vector<int> pos(nums.size(), -1);
        vector<int> sums(nums.size(), -1);
        if (nums[0] >= s) {
            pos[0] = 0;
        }
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int new_sum = sums[i-1] + nums[i];
            if (new_sum >= s) {
                if (pos[i-1] == -1) {
                    pos[i] = 0;
                    sums[i] = new_sum;
                } else {
                    int idx = pos[i-1];
                    while (new_sum - nums[idx] >= s) {
                        new_sum -= nums[idx];
                        ++idx;
                    }
                    pos[i] = idx;
                    sums[i] = new_sum;
                }
            } else {
                pos[i] = -1;
                sums[i] = new_sum;
            }
        }
        int min_len = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (pos[i] != -1 && i - pos[i] + 1 < min_len) {
                min_len = i - pos[i] + 1;
            }
        }
        if (min_len == nums.size() + 1) return -1;
        else return min_len;
    }
};

int main() {
    Solution s;
    return 0;
}

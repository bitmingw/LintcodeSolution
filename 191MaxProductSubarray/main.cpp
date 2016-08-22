#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> pos_prod(nums.size(), 0);
        vector<int> neg_prod(nums.size(), 0);
        if (nums[0] > 0) pos_prod[0] = nums[0];
        else if (nums[0] < 0) neg_prod[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                if (pos_prod[i-1]) pos_prod[i] = pos_prod[i-1] * nums[i];
                else pos_prod[i] = nums[i];
                if (neg_prod[i-1]) neg_prod[i] = neg_prod[i-1] * nums[i];
            } else if (nums[i] < 0) {
                if (pos_prod[i-1]) neg_prod[i] = pos_prod[i-1] * nums[i];
                else neg_prod[i] = nums[i];
                if (neg_prod[i-1]) pos_prod[i] = neg_prod[i-1] * nums[i];
            }
        }

        int max_val = pos_prod[0];
        for (int i = 1; i < pos_prod.size(); ++i) {
            if (pos_prod[i] > max_val) max_val = pos_prod[i];
        }
        return max_val;
    }
};

int main() {
    Solution s;
    return 0;
}

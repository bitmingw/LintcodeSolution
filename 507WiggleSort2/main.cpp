#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size(), 0);
        if (nums.size() % 2 == 0) {
            int lo = 0;
            int hi = ans.size() - 1;
            int len = ans.size() / 2;
            for (int i = 0; i < len; ++i) {
                ans[lo] = nums[i];
                lo += 2;
            }
            for (int i = 0; i < len; ++i) {
                ans[hi] = nums[nums.size()-i-1];
                hi -= 2;
            }
        } else {
            int lo = 0;
            int hi = ans.size() - 2;
            int len = ans.size() / 2;
            for (int i = 0; i <= len; ++i) {
                ans[lo] = nums[i];
                lo += 2;
            }
            for (int i = 0; i < len; ++i) {
                ans[hi] = nums[nums.size()-i-1];
                hi -= 2;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = ans[i];
        }
    }
};

int main() {
    Solution s;
    return 0;
}

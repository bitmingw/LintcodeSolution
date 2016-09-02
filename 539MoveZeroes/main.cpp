#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] && (i != pos)) {
                nums[pos] = nums[i];
                nums[i] = 0;
                ++pos;
            } else if (nums[i]) {
                ++pos;
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

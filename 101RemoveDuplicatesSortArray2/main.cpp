#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int current_num = nums[0];
        int current_times = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == current_num) {
                ++current_times;
                if (current_times > 2) {
                    nums.erase(nums.begin() + i);
                    --i;
                }
            } else {
                current_num = nums[i];
                current_times = 1;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    return 0;
}

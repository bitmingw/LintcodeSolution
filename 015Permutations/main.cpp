#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> permutes;
        if (nums.empty()) return permutes;
        vector<int> buf;
        vector<bool> used(nums.size(), false);
        findPermute(permutes, buf, used, nums);
        return permutes;
    }

    void findPermute(vector<vector<int>> &permutes, vector<int> &buf, vector<bool> &used, vector<int> &nums) {
        if (buf.size() == nums.size()) {
            permutes.push_back(buf);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            buf.push_back(nums[i]);
            findPermute(permutes, buf, used, nums);
            buf.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

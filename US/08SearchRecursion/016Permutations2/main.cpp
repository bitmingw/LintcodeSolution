#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int>> uniPermutes;
        if (nums.empty()) return uniPermutes;
        vector<int> buf;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        findUniPermute(uniPermutes, buf, used, nums);
        return uniPermutes;
    }

    void findUniPermute(vector<vector<int>> &permutes, vector<int> &buf, vector<bool> &used, vector<int> &nums) {
        if (buf.size() == nums.size()) {
            permutes.push_back(buf);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;  // must pick the first element
            used[i] = true;
            buf.push_back(nums[i]);
            findUniPermute(permutes, buf, used, nums);
            buf.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

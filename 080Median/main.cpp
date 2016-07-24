#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1) / 2];
    }
};

int main() {
    Solution s;
    return 0;
}

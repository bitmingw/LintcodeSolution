#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer (the length of new array)
     */
    int removeDuplicates(vector<int> &nums) {
        if (!nums.size()) return 0;
        int i = 0, vec_len = nums.size();
        for (; i < vec_len-1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums.erase(nums.begin()+i+1);
                --i;
                --vec_len;
            }
        }
        return vec_len;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums;
        int partNum, partPos = -1;
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                partNum = nums[i];
                partPos = i;
                break;
            }
        }
        if (partPos > -1) {
            int largerPos;
            for (int i = nums.size()-1; i >= 0; --i) {
                if (nums[i] > partNum) {
                    largerPos = i;
                    break;
                }
            }
            int tmp = nums[partPos];
            nums[partPos] = nums[largerPos];
            nums[largerPos] = tmp;
            for (int i = partPos+1, j = nums.size()-1; i < j; ++i, --j) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        } else {
            int tmp;
            for (int i = 0, j = nums.size()-1; i < j; ++i, --j) {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return nums;
    }
};

int main() {
    Solution s;
    return 0;
}

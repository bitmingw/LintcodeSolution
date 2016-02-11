#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        int minSum = nums[0];
        int currentSum = 0;

        for (int n: nums) {
            currentSum += n;
            if (currentSum < minSum) minSum = currentSum;
            if (currentSum > 0) currentSum = 0;
        }
        return minSum;
    }
};

int main() {
    Solution s;
    return 0;
}

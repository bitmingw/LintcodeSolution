#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.size() == 0) return 0;
        const int n = nums.size();
        vector<int> localMax(n, INT32_MIN);
        vector<int> globalMax(n, INT32_MIN);
        localMax[0] = nums[0];
        globalMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            localMax[i] = max(localMax[i-1] + nums[i], nums[i]);
            globalMax[i] = max(globalMax[i-1], localMax[i]);
        }
        localMax[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            localMax[i] = max(localMax[i+1] + nums[i], nums[i]);
        }
        int maxSum = INT32_MIN;
        for (int i = 0; i+1 < n; ++i) {
            if (globalMax[i] + localMax[i+1] > maxSum) {
                maxSum = globalMax[i] + localMax[i+1];
            }
        }
        return maxSum;
    }
};

int main() {
    Solution s;
    vector<int> testarr = vector<int>();
    testarr.push_back(-4);
    testarr.push_back(5);
    testarr.push_back(-4);
    testarr.push_back(5);
    testarr.push_back(-1000);
    cout << s.maxTwoSubArrays(testarr) << endl;
    return 0;
}

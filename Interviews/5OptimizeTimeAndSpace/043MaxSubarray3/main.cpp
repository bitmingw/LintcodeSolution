#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        const int n = nums.size();
        if (n == 0 || k <= 0 || n < k) return 0;
        vector<vector<int>> globalMax(k+1, vector<int>(n+1, 0));
        for (int i = 1; i <= k; ++i) {
            int localMax = INT32_MIN;
            for (int j = i-1; j < n; ++j) {
                localMax = max(globalMax[i-1][j], localMax) + nums[j];
                if (j == i-1)
                    globalMax[i][j+1] = localMax;
                else
                    globalMax[i][j+1] = max(globalMax[i][j], localMax);
            }
        }
        return globalMax[k][n];
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
    cout << s.maxSubArray(testarr, 2) << endl;  // should be 10
    cout << s.maxSubArray(testarr, 4) << endl;  // should be 2
    return 0;
}

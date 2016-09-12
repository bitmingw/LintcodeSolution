#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int d = 1; d <= n; ++d) {
            for (int i = 1; i <= n-d+1; ++i) {
                int j = i+d-1;
                int max_val = 0;
                for (int k = i; k <= j; ++k) {
                    int val = nums[i-1] * nums[k] * nums[j+1];
                    val += dp[i][k-1];
                    val += dp[k+1][j];
                    max_val = max(max_val, val);
                }
                dp[i][j] = max(dp[i][j], max_val);
            }
        }
        return dp[1][n];
    }
};

int main() {
    Solution s;
    vector<int> data = {4, 1, 5};
    cout << s.maxCoins(data) << endl;
    return 0;
}

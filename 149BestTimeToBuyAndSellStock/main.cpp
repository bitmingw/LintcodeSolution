#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        vector<int> price_diff;
        for (int i = 0; i < prices.size() - 1; ++i) {
            price_diff.push_back(prices[i+1] - prices[i]);
        }

        // find the max sum of subarray for price_diff
        int max_ending = price_diff[0];
        int max_so_far = max_ending;
        for (int i = 1; i < price_diff.size(); ++i) {
            max_ending = max(price_diff[i], max_ending + price_diff[i]);
            max_so_far = max(max_so_far, max_ending);
        }
        if (max_so_far < 0) return 0;
        return max_so_far;
    }
};


int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>

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

        int sum_positive = 0;
        for (int i = 0; i < price_diff.size(); ++i) {
            if (price_diff[i] > 0) sum_positive += price_diff[i];
        }
        return sum_positive;
    }
};


int main() {
    Solution s;
    return 0;
}

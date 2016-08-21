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

        vector<int> profits(prices.size(), 0);
        int buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profits[i] = max(profits[i-1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            best = max(best, sell - prices[i] + profits[i]);
            sell = max(sell, prices[i]);
        }
        return best;
    }
};


int main() {
    Solution s;
    return 0;
}

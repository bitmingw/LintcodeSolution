#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty() || prices.size() == 1) return 0;
        if (k >= prices.size() - 1) {
            int sum = 0;
            for (int i = 0; i+1 < prices.size(); ++i) {
                if (prices[i+1] - prices[i] > 0) sum += prices[i+1] - prices[i];
            }
            return sum;
        }
        vector<int> sells(k+1, 0);
        vector<int> total(k+1, 0);
        for (int i = 0; i+1 < prices.size(); ++i) {
            int inc = prices[i+1] - prices[i];
            for (int j = k; j >= 1; --j) {
                sells[j] = max(total[j-1] + max(inc, 0), sells[j] + inc);
                total[j] = max(total[j], sells[j]);
            }
        }
        return total[k];
    }
};

int main() {
    Solution s;
    return 0;
}

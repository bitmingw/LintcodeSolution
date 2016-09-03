#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        vector<vector<double>> iter_table(n+1, vector<double>(6*n+1, 0.0));
        for (int j = 1; j <= 6; ++j) {
            iter_table[1][j] = 1.0 / 6;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= i + 5; ++j) {
                for (int k = 0; k < 5*(i-1)+1; ++k) {
                    iter_table[i][j+k] += (1.0 / 6) * iter_table[i-1][i-1+k];
                }
            }
        }
        vector<pair<int, double>> res;
        for (int j = 0; j <= 6*n; ++j) {
            if (iter_table[n][j] != 0.0) {
                res.push_back(make_pair(j, iter_table[n][j]));
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

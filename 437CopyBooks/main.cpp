#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        if (pages.empty()) return 0;
        int n = pages.size();
        if (k >= n) {
            int max_page = INT32_MIN;
            for (int num: pages) max_page = max(max_page, num);
            return max_page;
        }
        // calculate the time interval
        vector<vector<int>> interval(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = i; k <= j; ++k) {
                    interval[i][j] += pages[k-1];
                }
            }
        }
        // calculate the optimal time
        vector<vector<int>> min_time(n+1, vector<int>(k+1));
        // only one person
        for (int i = 1; i <= n; ++i) {
            min_time[i][1] = interval[1][i];
        }
        // only one book
        for (int i = 1; i <= k; ++i) {
            min_time[1][i] = pages[0];
        }
        // do DP
        for (int kk = 2; kk <= k; ++kk) {
            int p = 1;
            for (int i = 1; i <= n; ++i) min_time[i][kk] = max(min_time[i-1][kk], pages[i-1]);
            for (int i = kk; i <= n; ++i) {
                while (p+1 < i && min_time[p][kk-1] < interval[p+1][i]) ++p;
                min_time[i][kk] = max(min_time[p][kk-1], interval[p+1][i]);
                if (p > 1) --p;
                min_time[i][kk] = min(min_time[i][kk], max(min_time[p][kk-1], interval[p+1][i]));
            }
        }
        /*
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                cout << min_time[i][j] << " ";
            }
            cout << endl;
        }
        */
        return min_time[n][k];
    }
};

int main() {
    Solution s;
    vector<int> data = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << s.copyBooks(data, 6) << endl;
    return 0;
}

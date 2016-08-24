#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        vector<int> coef = get_coef_table(n);
        vector<int> numbers;
        string res;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        k = k - 1;
        for (int i = 0; i < n - 1; ++i) {
            int idx = k / coef[i];
            res += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
            k = k % coef[i];
        }
        res += to_string(numbers[0]);
        return res;
    }

    vector<int> get_coef_table(int n) {
        vector<int> table(n, 0);
        if (n > 1) table[n-2] = 1;
        int cnt = 2;
        for (int i = n-3; i >= 0; --i) {
            table[i] = table[i+1] * cnt;
            ++cnt;
        }
        return table;
    }
};

int main() {
    Solution s;
    return 0;
}

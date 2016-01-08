#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        if (n <= 0 || n < k) return result;
        vector<int> eachSol;
        getCombinations(result, eachSol, n, k, 1);
        return result;
    }

    void getCombinations(vector<vector<int>> &result, vector<int> &sol, int n, int k, int num) {
        if (sol.size() == k) {
            // successfully generate one solution
            result.push_back(sol);
            return;
        }
        for (int i = num; i <= n; ++i) {
            sol.push_back(i);  // push this number to solution
            getCombinations(result, sol, n, k, i+1);  // recursively go with other numbers
            sol.pop_back();  // remove the last number to make room for new one
        }
    }
};

int main() {
    Solution s;
    return 0;
}

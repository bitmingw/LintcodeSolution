#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        if (!candidates.size()) return results;
        vector<int> eachSol;
        getAllCombinations(candidates, results, eachSol, target, 0, 0);
        for (int i = 0; i < results.size(); ++i)
            sort(results[i].begin(), results[i].end());
        return results;
    }

    void getAllCombinations(vector<int> &candidates, vector<vector<int>> &results, vector<int> &sol, int target, int nextIdx, int curSum) {
        if (curSum > target) return;
        if (curSum == target) {
            results.push_back(sol);
            return;
        }
        for (int i = nextIdx; i < candidates.size(); ++i) {
            sol.push_back(candidates[i]);
            getAllCombinations(candidates, results, sol, target, i, curSum + candidates[i]);  // a number can be repeated
            sol.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}

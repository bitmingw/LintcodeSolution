#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
     vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> allSets;
        vector<int> subset;
        allSets.push_back(subset);
        if (nums.empty()) return allSets;
        vector<int> sortedS(nums);
        sort(sortedS.begin(), sortedS.end());
        for (int i = 1; i <= sortedS.size(); ++i) {
            subset.clear();
            combination(sortedS, allSets, subset, i, 0);
        }
        return allSets;
    }

    void combination(vector<int> &array, vector<vector<int>> &allSets, vector<int> &set, int i, int idx) {
        if (set.size() == i) {
            allSets.push_back(set);
            return;
        }
        for (int j = idx; j < array.size(); ++j) {
            set.push_back(array[j]);
            combination(array, allSets, set, i, j+1);
            set.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}

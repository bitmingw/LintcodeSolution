#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        set<vector<int>> res;
        if (num.empty()) return vector<vector<int>>();
        sort(num.begin(), num.end());
        vector<int> buf;
        for (int i = 0; i < num.size(); ++i) {
            buf.push_back(num[i]);
            add_to_combination(num, target - num[i], i, buf, res);
            buf.pop_back();
        }
        vector<vector<int>> vres;
        for (auto elem: res) {
            vres.push_back(elem);
        }
        return vres;
    }

    void add_to_combination(vector<int>& num, int target, int start_idx, vector<int>& buf, set<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.insert(buf);
            return;
        }
        for (int i = start_idx + 1; i < num.size(); ++i) {
            buf.push_back(num[i]);
            add_to_combination(num, target - num[i], i, buf, res);
            buf.pop_back();
        }
    }
};

int main() {
    Solution s;
    return 0;
}

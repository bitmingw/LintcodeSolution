#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int a = 0;
        int b = 1;
        while (a < nums.size() - 3) {
            b = a + 1;
            while (b < nums.size() - 2) {
                int c = b + 1;
                int d = nums.size() - 1;
                while (c < d) {
                    int val = nums[a] + nums[b] + nums[c] + nums[d];
                    if (val == target) {
                        pushTuple(res, nums, a, b, c, d);
                        ++c;
                        --d;
                    } else if (val < target) {
                        ++c;
                    } else {
                        --d;
                    }
                }
                ++b;
            }
            ++a;
        }
        return res;
    }

    void pushTuple(vector<vector<int>>& res, vector<int>& nums, int a, int b, int c, int d) {
        vector<int> found = {nums[a], nums[b], nums[c], nums[d]};
        
        // add the new vector only if it is unique
        bool unique = true;
        for (vector<int> v: res) {
            for (int i = 0; i < 4; ++i) {
                if (v[i] != found[i]) {
                    break;
                }
                if (i == 3) unique = false;
            }
        }
        if (unique) res.push_back(found);
        return;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,0,-1,-1,-1,-1,0,1,1,1,2};
    vector<vector<int>> res = s.fourSum(nums, 2);
    for (vector<int> v: res) {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    }
    return 0;
}

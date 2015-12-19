#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // assume we can find at least one triple
        sort(nums.begin(), nums.end());
        set<vector<int>> triplets;
        int lo, hi, sum;
        for (int i = 0; i <= nums.size()-3; ++i) {
            lo = i+1;
            hi = nums.size()-1;
            while (lo < hi) {
                sum = nums[i] + nums[lo] + nums[hi];
                if (sum == 0) {
                    triplets.insert(gen_triplet(nums[i], nums[lo], nums[hi]));
                    ++lo;
                    --hi;
                } else if (sum < 0) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        vector<vector<int>> combinations;
        for (set<vector<int>>::iterator it = triplets.begin(); it != triplets.end(); ++it) {
            combinations.push_back(*it);
        }
        return combinations;
    }

    vector<int> gen_triplet(int idx1, int idx2, int idx3) {
        vector<int> triplet;
        triplet.push_back(idx1);
        triplet.push_back(idx2);
        triplet.push_back(idx3);
        sort(triplet.begin(), triplet.end());
        return triplet;
    }
};

int main() {
    Solution s;
    return 0;
}

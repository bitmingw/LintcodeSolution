#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // assume we always have exactly one solution
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int closest;
        int lo, hi;
        for (int i = 0; i <= nums.size()-3; ++i) {
            lo = i+1;
            hi = nums.size()-1;
            while (lo < hi) {
                if (abs(target - (nums[i]+nums[lo]+nums[hi])) < abs(diff)) {
                    diff = target - (nums[i]+nums[lo]+nums[hi]);
                    closest = nums[i] + nums[lo] + nums[hi];
                    // cout << nums[i] << " " << nums[lo] << " " << nums[hi] << endl;
                }
                if (target - (nums[i]+nums[lo]+nums[hi]) > 0) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return closest;
    }
};

int main() {
    Solution s;
    int arr[] = {-1, 2, 1, -4};
    vector<int> vec(arr, arr+4);
    int arr2[] = {1,2,33,23,2423,33,23,1,7,6,8787,5,33,2,3,-23,-54,-67,100,400,-407,-500,-35,-8,0,0,7,6,0,1,2,-56,-89,24,2};
    vector<int> vec2(arr2, arr2+35);
    // cout << s.threeSumClosest(vec, 1) << endl;  // should be 2
    cout << s.threeSumClosest(vec2, 148) << endl;  // should be 147
    return 0;
}

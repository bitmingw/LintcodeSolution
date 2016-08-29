#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        if (nums.empty()) return 0;
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -1 && nums[i] != i) {
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
                --i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == -1) return i;
        }
    }
};

int main() {
    Solution s;
    vector<int> data = {9,8,7,6,2,0,1,5,4};
    cout << s.findMissing(data) << endl;  // should be 3
    return 0;
}

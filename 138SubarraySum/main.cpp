#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // assume there is at least one subarry that sum = 0
        vector<int> indices;
        int vec_len = nums.size();
        int sum;
        for (int i = 0; i < vec_len; ++i) {
            sum = nums[i];
            if (sum == 0) {
                indices.push_back(i);
                indices.push_back(i);
                return indices;
            } else {
                for (int j = i+1; j < vec_len; ++j) {
                    sum += nums[j];
                    if (sum == 0) {
                        indices.push_back(i);
                        indices.push_back(j);
                        return indices;
                    }
                }
            }
        }
        // should not go here
        return indices;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;
        int *matrix = new int[nums.size()];
        matrix[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int max_val = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i] && matrix[j] >= max_val) {
                    max_val = matrix[j] + 1;
                }
            }
            matrix[i] = max_val;
        }
        int max_res = matrix[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (matrix[i] > max_res) max_res = matrix[i];
        }
        delete matrix;
        return max_res;
    }
};

int main() {
    Solution s;
	return 0;
}

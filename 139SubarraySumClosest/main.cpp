#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // assume nums has at least one element
        if (nums.size() == 1) {
            vector<int> res = {0, 0};
            return res;
        }

        vector<int> prefix_vec;
        int prefix_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            prefix_vec.push_back(prefix_sum);
        }
        vector<int> origin_prefix_vec(prefix_vec.begin(), prefix_vec.end());
        sort(prefix_vec.begin(), prefix_vec.end());
        int min_diff = INT32_MAX;
        int min_diff_pos = -1;
        for (int i = 0; i < prefix_vec.size() - 1; ++i) {
            if (prefix_vec[i+1] - prefix_vec[i] < min_diff) {
                min_diff = prefix_vec[i+1] - prefix_vec[i];
                min_diff_pos = i;
            }
        }
        int begin_pos = -1;
        int end_pos = -1;
        if (min_diff == 0) {
            int target = prefix_vec[min_diff_pos];
            for (int i = 0; i < origin_prefix_vec.size(); ++i) {
                if (begin_pos == -1 && origin_prefix_vec[i] == target) {
                    begin_pos = i;
                } else if (begin_pos != -1 && origin_prefix_vec[i] == target) {
                    end_pos = i;
                    break;
                }
            }
        } else {
            for (int i = 0; i < origin_prefix_vec.size(); ++i) {
                if (origin_prefix_vec[i] == prefix_vec[min_diff_pos]) {
                    begin_pos = i;
                } else if (origin_prefix_vec[i] == prefix_vec[min_diff_pos+1]) {
                    end_pos = i;
                }
            }
            if (begin_pos > end_pos) {
                int tmp = begin_pos;
                begin_pos = end_pos;
                end_pos = tmp;
            }
        }
        vector<int> res = {begin_pos+1, end_pos};
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

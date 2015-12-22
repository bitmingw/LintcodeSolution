#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> sorted_nums(nums);
        vector<int> result;
        int sorted_idx1 = -1, sorted_idx2 = -1, idx1 = -1, idx2 = -1;
        sort(sorted_nums.begin(), sorted_nums.end());
        int to_find, sorted_idx;
        for (int i = 0; i < sorted_nums.size(); ++i) {
            to_find = target - sorted_nums[i];
            sorted_idx = binSearch(sorted_nums, to_find, i+1, sorted_nums.size()-1);
            if (sorted_idx > 0) {
                sorted_idx1 = i;
                sorted_idx2 = sorted_idx;
                break;
            }
        }
        // find indices in original vector
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == sorted_nums[sorted_idx1])
                idx1 = i;
            if (nums[i] == sorted_nums[sorted_idx2])
                idx2 = i;
            if (idx1 >= 0 && idx2 >= 0)
                break;
        }
        result.push_back(min(idx1, idx2)+1);
        result.push_back(max(idx1, idx2)+1);
        return result;
    }
    
    int binSearch(vector<int>& vec, int target, int lo, int hi) {
        if (lo > hi) return -1;
        int mi = (lo + hi) / 2;
        if (vec[mi] == target) return mi;
        else if (vec[mi] < target) return binSearch(vec, target, mi+1, hi);
        else return binSearch(vec, target, lo, mi-1);
    }
};

int main() {
    Solution s;
    return 0;
}

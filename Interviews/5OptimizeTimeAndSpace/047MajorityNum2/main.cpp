#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
     int majorityNumber(vector<int> nums) {
         int num1, num2, cnt1, cnt2;
         if (nums.size() == 1) return nums[0];
         num1 = nums[0];
         num2 = INT_MAX;
         cnt1 = 1;
         cnt2 = 0;
         for (int i = 1; i < nums.size(); ++i) {
             if (nums[i] == num1) {
                 ++cnt1;
             } else if (nums[i] == num2) {
                 ++cnt2;
             } else if (cnt1 == 0) {
                 num1 = nums[i];
                 ++cnt1;
             } else if (cnt2 == 0) {
                 num2 = nums[i];
                 ++cnt2;
             } else {
                 --cnt1;
                 --cnt2;
             }
         }
         cnt1 = 0; cnt2 = 0;
         for (int i = 0; i < nums.size(); ++i) {
             if (nums[i] == num1) ++cnt1;
             if (nums[i] == num2) ++cnt2;
         }
         if (cnt1 > cnt2) return num1;
         else return num2;
     }
};

int main() {
    Solution s;
    return 0;
}

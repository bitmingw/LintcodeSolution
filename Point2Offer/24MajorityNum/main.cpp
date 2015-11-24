#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main() {
    return 0;
}

#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        map<int, int> countTable;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); ++i) {
            it = countTable.find(nums[i]);
            if (it == countTable.end()) countTable[nums[i]] = 1;
            else ++countTable[nums[i]];
        }
        int maxNum, maxOccur = 0;
        for (map<int, int>::iterator it = countTable.begin(); it != countTable.end(); ++it) {
            if (it->second > maxOccur) {
                maxNum = it->first;
                maxOccur = it->second;
            }
        }
        return maxNum;
    }
};

int main() {
    Solution s;
    return 0;
}

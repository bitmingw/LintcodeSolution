#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int headIdx = 0;
        int tailIdx = num.size()-1;
        int medIdx = 0;
        
        // special case: rotate 0 elements
        if (num[headIdx] <= num[tailIdx]) {
            return num[headIdx];
        }
        // normal case
        while (headIdx < tailIdx) {
            // found
            if (tailIdx == headIdx + 1) {
                return num[tailIdx];
            }
            // binary search
            medIdx = (headIdx + tailIdx) / 2;
            if (num[medIdx] > num[headIdx]) {
                headIdx = medIdx;
            }
            if (num[medIdx] < num[tailIdx]) {
                tailIdx = medIdx;
            }
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(2);
    
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}

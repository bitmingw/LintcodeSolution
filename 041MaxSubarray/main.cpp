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
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int currentSum = *nums.begin();
        int maxSum = currentSum;
        if (currentSum < 0) currentSum = 0;
        
        for (vector<int>::iterator it = nums.begin()+1; it != nums.end(); ++it) {
            currentSum += *it;
            if (currentSum < 0) {
                currentSum = 0;
            } else if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        
        return maxSum;
    }
};

int main() {
    Solution s;
    vector<int> testarr = vector<int>();
    testarr.push_back(-4);
    testarr.push_back(5);
    testarr.push_back(-4);
    testarr.push_back(5);
    testarr.push_back(-1000);
    /*
    testarr.push_back(2);
    testarr.push_back(1);
    testarr.push_back(-5);
    testarr.push_back(3);
    */
    cout << s.maxSubArray(testarr) << endl;
    return 0;
}

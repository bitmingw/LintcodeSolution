#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> bArray = vector<long long>(nums.size(), 1);
        for (int i = 0; i < bArray.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) bArray[i] *= nums[j];
            }
        }
        return bArray;
    }
};

int main() {
    Solution s;
    return 0;
}

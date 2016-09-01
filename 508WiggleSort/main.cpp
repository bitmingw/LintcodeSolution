#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 0 && nums[i] > nums[i-1]) ||
                (i % 2 == 1 && nums[i] < nums[i-1])) {
                int tmp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = tmp;        
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

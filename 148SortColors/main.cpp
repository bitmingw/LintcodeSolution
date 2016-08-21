#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        vector<int> count = {0, 0, 0};
        for (int n: nums) {
            count[n] += 1;
        }

        int color = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count[color] > 0) {
                nums[i] = color;
                --count[color];
            } else {
                color += 1;
                --i;
            }
        }
        return;
    }
};

int main() {
    Solution s;
    return 0;
}

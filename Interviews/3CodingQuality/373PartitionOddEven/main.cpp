#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int forward = 0;
        int reverse = nums.size() - 1;
        while (forward < reverse) {
            if (nums[forward] % 2 == 1) {
                ++forward;
                continue;
            }
            if (nums[reverse] % 2 == 0) {
                --reverse;
                continue;
            }
            int tmp = nums[forward];
            nums[forward] = nums[reverse];
            nums[reverse] = tmp;
            ++forward;
            --reverse;
        }
    }
};
 

int main() {
    vector<int> line = vector<int>();
    line.push_back(1);
    line.push_back(2);
    line.push_back(3);
    line.push_back(4);
    
    Solution s;
    s.partitionArray(line);
    for (vector<int>::iterator it = line.begin(); it != line.end(); ++it) {
        cout << *it << " " << endl;
    }
    
	return 0;
}

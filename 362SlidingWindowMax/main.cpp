#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // assume k > 0 and nums.size() >= k
        vector<int> smax;
        deque<int> indexq;
        for (int i = 0; i < nums.size(); ++i) {
            // remove previous smaller elements
            while (indexq.size() && nums[indexq.back()] <= nums[i])
                indexq.pop_back();
            // add this element to the end
            indexq.push_back(i);
            // remove the head element if it is out of sliding window
            if (indexq.front() < i - k + 1) indexq.pop_front();
            // get the result for this round
            if (i + 1 >= k) smax.push_back(nums[indexq.front()]);
        }
        return smax;
    }
};

int main() {
	Solution s = Solution();
	return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if (heights.size() < 3) return 0;
        vector<int> lwall(heights.size());
        vector<int> rwall(heights.size());
        vector<int> max_heights(heights.size());
        int lmax = heights[0];
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] > lmax) lmax = heights[i];
            lwall[i] = lmax;
        }
        int rmax = heights[heights.size() - 1];
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (heights[i] > rmax) rmax = heights[i];
            rwall[i] = rmax;
        }
        for (int i = 0; i < max_heights.size(); ++i) {
            max_heights[i] = min(lwall[i], rwall[i]);
        }
        int sum = 0;
        for (int i = 0; i < max_heights.size(); ++i) {
            sum += max_heights[i] - heights[i];
        }
        return sum;
    }
};

int main() {
	Solution s = Solution();
	return 0;
}

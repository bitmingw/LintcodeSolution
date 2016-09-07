#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // assume non-negative numbers
        if (heights.size() < 2) return 0;
        int fp = 0;
        int bp = heights.size() - 1;
        int volumn = min(heights[fp], heights[bp]) * (bp - fp);
        while (fp < bp) {
            if (heights[fp] < heights[bp]) {
                ++fp;
            } else if (heights[fp] > heights[bp]) {
                --bp;
            } else {
                // two are equal
                if (min(heights[fp+1], heights[bp]) >= min(heights[fp], heights[bp-1])) {
                    ++fp;
                } else {
                    --bp;
                }
            }
            volumn = max(volumn, min(heights[fp], heights[bp]) * (bp - fp));
        }
        return volumn;
    }
};

int main() {
    Solution s;
    return 0;
}

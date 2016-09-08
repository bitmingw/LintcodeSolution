#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Block {
public:
    int min;
    int max;
    Block() : min(-1), max(-1) {}
};

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        if (nums.size() < 2) return 0;
        int min_val = INT32_MAX;
        int max_val = INT32_MIN;
        for (auto n: nums) {
            min_val = min(min_val, n);
            max_val = max(max_val, n);
        }
        if (min_val == max_val) return 0;
        int nblock = nums.size();
        int range = (max_val - min_val) / nblock + 1;
        vector<Block> blocks(nblock, Block());
        for (auto n: nums) {
            int idx = (n - min_val) / range;
            if (blocks[idx].max == -1) {
                blocks[idx].min = n;
                blocks[idx].max = n;
            } else {
                blocks[idx].min = min(blocks[idx].min, n);
                blocks[idx].max = max(blocks[idx].max, n);
            }
        }
        int max_gap = -1;
        int last_num = blocks[0].max;
        for (int i = 1; i < nums.size(); ++i) {
            if (blocks[i].min == -1) continue;
            max_gap = max(max_gap, blocks[i].min - last_num);
            last_num = blocks[i].max;
        }
        return max_gap;
    }
};

int main() {
    Solution s;
    return 0;
}

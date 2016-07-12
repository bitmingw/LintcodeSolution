#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        vector<int> pre(nums);
        if (pre.size() <= 1) return pre;
        int partIdx = -1;
        int partNum = -1;
        for (int i = pre.size() - 2; i >= 0; --i) {
            if (pre[i] > pre[i+1]) {
                partIdx = i;
                partNum = pre[i];
                break;
            }
        }
        if (partIdx != -1) {
            int smallIdx = -1;
            for (int i = pre.size() - 1; i >= 0; --i) {
                if (pre[i] < partNum) {
                    smallIdx = i;
                    break;
                }
            }
            int tmp = pre[smallIdx];
            pre[smallIdx] = pre[partIdx];
            pre[partIdx] = tmp;
            for(int i = partIdx + 1, j = pre.size() - 1; i < j; ++i, --j) {
                int tmp = pre[i];
                pre[i] = pre[j];
                pre[j] = tmp;
            }
        } else {
            for (int i = 0, j = pre.size() - 1; i < j; ++i, --j) {
                int tmp = pre[i];
                pre[i] = pre[j];
                pre[j] = tmp;
            }
        }
        return pre;
    }
};

int main() {
    Solution s;
    return 0;
}

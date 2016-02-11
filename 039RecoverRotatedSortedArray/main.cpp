#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums[0] < nums[nums.size()-1]) return;  // not rotated
        recover(nums, 0, nums.size()-1);
    }

    void recover(vector<int> &nums, int begin, int end) {
        // find the pivot point
        if (nums[begin] < nums[end]) return;
        int pivot = end;
        for (int i = begin; i+1 <= end; ++i) {
            if (nums[i] > nums[i+1]) {
                pivot = i;
                break;
            }
        }
        int leftSize = pivot - begin + 1;
        int rightSize = end - pivot;
        if (leftSize < rightSize) {
            for (int i = 0; i < leftSize; ++i) {swap(nums, begin+i, end-leftSize+i+1);}
            recover(nums, begin, end-leftSize);
        } else if (leftSize > rightSize) {
            for (int i = 0; i < rightSize; ++i) {swap(nums, begin+leftSize-rightSize+i, pivot+i+1);}
            recover(nums, begin, end-rightSize);
        } else {
            for (int i = 0; i < leftSize; ++i) {swap(nums, begin+i, pivot+i+1);}
        }
    }

    void swap(vector<int> &nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
    }
};

int main() {
    Solution s;
	return 0;
}

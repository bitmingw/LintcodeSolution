#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> smedian;
        if (nums.empty() || k > nums.size()) return smedian;

        // construct two heaps
        multiset<int> left_heap, right_heap;
        for (int i = 0; i < nums.size(); ++i) {
            // insert into heap
            if (left_heap.empty() || right_heap.empty()) {
                left_heap.insert(nums[i]);
            } else {
                int left_range = *left_heap.rbegin();
                if (nums[i] <= left_range) left_heap.insert(nums[i]);
                else right_heap.insert(nums[i]);
            }

            make_balance(left_heap, right_heap);

            // remove previous out of range number
            if (i >= k) {
                int left_range = *left_heap.rbegin();
                if (nums[i - k] <= left_range) {
                    int erased = left_heap.erase(nums[i - k]);
                    while (erased > 1) {
                        left_heap.insert(nums[i - k]);
                        --erased;
                    }
                } else {
                    int erased = right_heap.erase(nums[i - k]);
                    while (erased > 1) {
                        right_heap.insert(nums[i - k]);
                        --erased;
                    }
                }
            }

            make_balance(left_heap, right_heap);

            // get the result
            if (i + 1 >= k) {
                smedian.push_back(*left_heap.rbegin());
            }
        }
        return smedian;
    }

    void make_balance(multiset<int>& left_heap, multiset<int>& right_heap) {
        if (left_heap.size() >= right_heap.size() + 2) {
            int elem = *left_heap.rbegin();
            int erased = left_heap.erase(elem);
            while (erased > 1) {
                left_heap.insert(elem);
                --erased;
            }
            right_heap.insert(elem);
        }
        if (right_heap.size() > left_heap.size()) {
            int elem = *right_heap.begin();
            int erased = right_heap.erase(elem);
            while (erased > 1) {
                right_heap.insert(elem);
                --erased;
            }
            left_heap.insert(elem);
        }
    }
};

int main() {
	Solution s = Solution();
    int data[] = {1, 2, 7, 7, 2};
    vector<int> data_vec(data, data+5);
    vector<int> res = s.medianSlidingWindow(data_vec, 1);
    for (int num: res) cout << num << " ";
    cout << endl;
	return 0;
}

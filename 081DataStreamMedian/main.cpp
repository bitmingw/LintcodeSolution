#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> seq_medians;
        priority_queue<int, vector<int>> left_heap;  // max heap
        priority_queue<int, vector<int>, greater<int>> right_heap;  // min heap
        for (int i = 0; i < nums.size(); ++i) {
            // determine the group to join
            if (left_heap.empty() || right_heap.empty()) {
                left_heap.push(nums[i]);
            } else {
                int left_group = left_heap.top();
                int right_group = right_heap.top();
                if (nums[i] <= left_group) left_heap.push(nums[i]);
                else right_heap.push(nums[i]);
            }
            // make balance
            if (left_heap.size() >= right_heap.size() + 2) {
                // should not use left_heap.size() - right_heap.size() >= 2
                int elem = left_heap.top();
                left_heap.pop();
                right_heap.push(elem);
            }
            if (right_heap.size() > left_heap.size()) {
                // should not use right_heap.size() - left_heap.size() > 0
                int elem = right_heap.top();
                right_heap.pop();
                left_heap.push(elem);
            }
            int median = left_heap.top();
            seq_medians.push_back(median);
        }
        return seq_medians;
    }
};

int main() {
    Solution s;
    int data[] = {1, 2, 3, 4, 5};
    vector<int> data_vec(data, data+5);
    vector<int> medians = s.medianII(data_vec);
    for (int num: medians) cout << num << " ";
    cout << endl;
    return 0;
}

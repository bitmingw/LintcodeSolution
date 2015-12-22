#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // assert k > 0
        int start = 0;
        int end = nums.size() - 1;
        int ksmall = nums.size() - k;
        int index = Partition(nums, start, end);
        while (index != ksmall) {
            if (index > ksmall) {
                end = index - 1;
                index = Partition(nums, start, end);
            } else {
                start = index + 1;
                index = Partition(nums, start, end);
            }
        }
        return nums[index];
    }

    int Partition(vector<int>& vec, int start, int end) {
        int num = vec[start]; // as the pivot
        int i = start, j = end + 1, tmp;
        while (true) {
            while (vec[++i] < num) if (i == end) break;
            while (vec[--j] > num) if (j == start) break;
            if (i >= j) break;
            // else: swap i and j
            tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
        // swap j and pivot
        tmp = vec[start];
        vec[start] = vec[j];
        vec[j] = tmp;
        return j;
    }
};

int main() {
    Solution s;
    int arr[] = {9, 3, 2, 4, 8};
    vector<int> v = vector<int>(arr, arr + sizeof(arr)/sizeof(int));
    cout << s.kthLargestElement(3, v) << endl; // should be 4
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        if (nums1.empty() || nums2.empty()) return vector<int>();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ptr1 = 0;
        int ptr2 = 0;
        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ++ptr1;
                continue;
            }
            if (nums1[ptr1] > nums2[ptr2]) {
                ++ptr2;
                continue;
            }
            res.insert(nums1[ptr1]);
            ++ptr1;
            ++ptr2;
        }
        vector<int> vres(res.begin(), res.end());
        return vres;
    }
};

int main() {
    Solution s;
    return 0;
}

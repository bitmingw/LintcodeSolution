#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        vector<vector<int>> res;
        vector<int> removed;
        for (int i = 0; i <= A.size() - k; ++i) {
            int new_target = target - A[i];
            removed.push_back(i);
            kSumIIDFS(res, A, k-1, new_target, removed);
            removed.pop_back();
        }
        return res;
    }

    void kSumIIDFS(vector<vector<int>>& res, vector<int>& A, int k, int target, vector<int>& removed) {
        if (k == 0) {
            if (target == 0) {
                vector<int> nums;
                for (int pos: removed) {
                    nums.push_back(A[pos]);
                }
                res.push_back(nums);
            }
        } else {
            for (int i = removed.back() + 1; i <= A.size() - k; ++i) {
                int new_target = target - A[i];
                removed.push_back(i);
                kSumIIDFS(res, A, k-1, new_target, removed);
                removed.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> data = {1, 2, 3, 4};
    cout << s.kSumII(data, 2, 5).size() << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // assume A is not empty
        int len = A.size();
        vector<vector<int>> max_table;
        vector<int> record = {A[0], 0, 0};
        max_table.push_back(record);
        for (int i = 1; i < len; ++i) {
            int previous_sum = max_table.back()[0];
            if (A[i] >= previous_sum + A[i]) {
                record = {A[i], i, i};
            } else {
                record = max_table.back();
                record[0] += A[i];
                record[2] = i;
            }
            max_table.push_back(record);
        }
        int max_pos = 0;
        int max_val = INT32_MIN;
        for (int i = 0; i < len; ++i) {
            if (max_table[i][0] > max_val) {
                max_val = max_table[i][0];
                max_pos = i;
            }
        }
        record = max_table[max_pos];
        return vector<int>(record.begin() + 1, record.end());
    }
};

int main() {
    Solution s;
    return 0;
}

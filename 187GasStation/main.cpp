#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (!gas.size() || !cost.size()) return -1;
        vector<int> remain;
        for (int i = 0; i < gas.size(); ++i) {
            remain.push_back(gas[i] - cost[i]);
        }
        int sum = 0, left = 0, start = 0;
        for (int i = 0; i < remain.size(); ++i) {
            left += remain[i];
            sum += remain[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        if (left < 0) return -1;
        return start;
    }
};

int main() {
    Solution s;
    return 0;
}

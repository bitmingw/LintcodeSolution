#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // assume A is not empty
        int goal = A.size() - 1;
        int jumps = 0;
        int current = 0;
        while (current < goal) {
            if (current + A[current] >= goal) return jumps + 1;
            int farthest = current;
            int best_idx = 0;
            for (int i = 1; i <= A[current]; ++i) {
                if (current + i + A[current + i] > farthest) {
                    farthest = current + i + A[current + i];
                    best_idx = i;
                }
            }
            current += best_idx;
            jumps += 1;
        }
        return jumps;
    }
};

int main() {
    Solution s;
    return 0;
}

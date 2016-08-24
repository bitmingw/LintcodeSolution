#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> smallers;
        if (A.empty()) return vector<int>(queries.size(), 0);
        sort(A.begin(), A.end());
        for (int num: queries) {
            if (num > A[A.size() - 1]) {
                smallers.push_back(A.size());
                continue;
            }
            int lo = 0;
            int hi = A.size() - 1;
            int mi;
            int target = -1;
            while (lo <= hi) {
                mi = (lo + hi) / 2;
                if (A[mi] == num && (mi == 0 || A[mi-1] != num)) {
                    target = mi;
                    break;
                } else if (A[mi] >= num) {
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            }
            if (target == -1) target = lo;
            smallers.push_back(target);
        }
        return smallers;
    }
};

int main() {
    Solution s;
    return 0;
}

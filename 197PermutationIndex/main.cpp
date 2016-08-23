#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        if (A.empty()) return 0;
        if (A.size() == 1) return 1;
        vector<int> sortedA(A);
        sort(sortedA.begin(), sortedA.end());
        int n = A.size();

        // build the factorial vector
        vector<long long> coef(n, 0);
        coef[n-2] = 1;
        int cnt = 2;
        for (int i = n-3; i >= 0; --i) {
            coef[i] = cnt * coef[i+1];
            ++cnt;
        }

        // get the index
        long long index = 0;
        for (int i = 0; i < n; ++i) {
            int bit_index = -1;
            for (int j = 0; j < sortedA.size(); ++j) {
                if (A[i] == sortedA[j]) {
                    bit_index = j;
                    break;
                }
            }
            index += coef[i] * bit_index;
            sortedA.erase(sortedA.begin() + bit_index);
        }
        return index + 1;
    }
};

int main() {
    Solution s;
    return 0;
}

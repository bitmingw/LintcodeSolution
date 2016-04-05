#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        if (S.size() < 3) return 0;
        sort(S.begin(), S.end());
        int i, j;
        int k = S.size() - 1;
        int cnt = 0;
        while (k >= 2) {
            i = 0;
            j = k - 1;
            while (i < j) {
                if (S[i] + S[j] <= S[k]) {
                    ++i;
                } else {
                    cnt += j - i;
                    --j;
                }
            }
            --k;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    return 0;
}

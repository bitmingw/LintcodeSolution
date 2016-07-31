#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<bool> bag(m+1, false);
        bag[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= A[i]; --j) {
                bag[j] = bag[j] || bag[j - A[i]];
            }
        }

        for (int j = m; j >= 0; --j) {
            if (bag[j]) return j;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

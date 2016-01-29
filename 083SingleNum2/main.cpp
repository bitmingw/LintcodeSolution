#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer
	 */
    int singleNumberII(vector<int> &A) {
        vector<int> bitMap(32, 0);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                bitMap[j] += (A[i] & 1);
                A[i] = A[i] >> 1;
            }
        }
        int val = 0;
        int base = 1;
        for (int j = 0; j < 32; ++j) {
            if (bitMap[j] % 3) val += base;
            base = base << 1;
        }
        return val;
    }
};

int main() {
    Solution s;
    return 0;
}

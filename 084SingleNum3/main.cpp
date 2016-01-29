#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        vector<int> result;
        if (!A.size()) return result;
        int remain = 0;
        for (int i = 0; i < A.size(); ++i) {
            remain ^= A[i];
        }
        int nBit = first1Bit(remain);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (!is1Bit(A[i], nBit)) num1 ^= A[i];
            else num2 ^= A[i];
        }
        result.push_back(num1);
        result.push_back(num2);
        return result;
    }

    int first1Bit(int num) {
        int bit = 0;
        for (int i = 0; i < 32; ++i) {
            if (num & 1) return bit;
            else {
                num = num >> 1;
                ++bit;
            }
        }
        return -1;
    }

    bool is1Bit(int num, int bit) {
        int mask = 1 << bit;
        return num & mask;
    }
};

int main() {
    Solution s;
    return 0;
}

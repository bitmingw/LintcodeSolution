#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int c = a ^ b;
        return count1s(c);
    }

    int count1s(int c) {
        int count = c & 1;
        for (int i = 1; i < 32; ++i) {
            c = (c >> 1) & 0x7FFFFFFF;
            count += c & 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    return 0;
}

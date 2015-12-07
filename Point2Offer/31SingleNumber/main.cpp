#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        if (!A.size()) return 0;
        int num = A[0];
        for (int i = 1; i < A.size(); ++i) {
            num ^= A[i];
        }
        return num;
    }
};

int main() {
    Solution s;
    return 0;
}

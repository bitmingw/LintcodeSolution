#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        if (A.size() < 2) return;
        for (int i = A.size()-1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] > A[j+1]) {
                    int tmp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = tmp;
                }
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

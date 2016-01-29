#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        if (!A.size() || k == A.size()) return "0";
        int count = 0;
        // first step: remove all the reverse order digits from begin to end
        for (int i = 0; i + 1 < A.size(); ++i) {
            if (isReverse(A, i)) {
                A.erase(i, 1);
                i = -1;  // reset the pointer to start
                ++count;
                if (count == k) break;
            }
        }
        // second step: remove from the end one by one
        while (count < k) {
            A.erase(A.size()-1, 1);
            ++count;
        }
        // remove front zeros
        while (A.size() > 1) {
            if (A[0] == '0') {
                A.erase(0, 1);
            } else {
                break;
            }
        }
        return A;
    }

    bool isReverse(const string &str, int pos) {
        return str[pos] > str[pos+1];
    }
};

int main() {
    Solution s;
    cout << s.DeleteDigits("178542", 4) << endl;  // should be 12
    cout << s.DeleteDigits("9597", 3) << endl;  // should be 5
    return 0;
}

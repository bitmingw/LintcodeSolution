#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // assume x >= 0
        if (x == 0) return 0;
        long long lo = 1, hi = x;
        long long mi;
        while (lo < hi) {
            mi = (lo + hi) / 2;
            if (mi * mi > x) hi = mi - 1;
            else if ((mi+1)*(mi+1) <= x) lo = mi + 1;
            else return mi;
        }
        return lo;
    }
};

int main() {
    Solution s;
    cout << s.sqrt(3) << " " << s.sqrt(4) << " " << s.sqrt(5) << " " << s.sqrt(10) << endl;
    // should be 1 2 2 3
    cout << s.sqrt(999999999) << endl;
    // should be 31622
	return 0;
}

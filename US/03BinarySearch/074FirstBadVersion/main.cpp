#include <iostream>
#include <vector>
using namespace std;

/*
class SVNRepo {
public:
    static bool isBadVersion(int k);
};
*/
// you can use SVNRepo::isBadVersion(k) to judge whether
// the kth code version is bad or not.

class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int lo = 1, hi = n;
        int mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (!SVNRepo::isBadVersion(mi)) lo = mi + 1;
            else hi = mi - 1;
        }
        return lo;
    }
};


int main() {
    Solution s;
	return 0;
}

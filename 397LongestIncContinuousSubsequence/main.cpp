#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // special case
        if (A.empty()) return 0;
        // scan increasing sequence
        int incLen = incSeq(A);
        // scan decreasing sequence
        int decLen = decSeq(A);
        return max(incLen, decLen);
    }

    int incSeq(vector<int>& A) {
        int cnt = 1;
        int maxCnt = cnt;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                ++cnt;
            } else {
                if (cnt > maxCnt) maxCnt = cnt;
                cnt = 1;
            }
        }
        if (cnt > maxCnt) maxCnt = cnt;
        return maxCnt;
    }

    int decSeq(vector<int>& A) {
        int cnt = 1;
        int maxCnt = cnt;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] < A[i-1]) {
                ++cnt;
            } else {
                if (cnt > maxCnt) maxCnt = cnt;
                cnt = 1;
            }
        }
        if (cnt > maxCnt) maxCnt = cnt;
        return maxCnt;
    }
};

int main() {
    Solution s;
	return 0;
}

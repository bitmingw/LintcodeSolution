#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        vector<int> dpTriPre(triangle.size(), 0);
        vector<int> dpTriPost(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); ++i) {
            dpTriPost[0] = dpTriPre[0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dpTriPost[j] = min(dpTriPre[j-1], dpTriPre[j]) + triangle[i][j];
            }
            if (i > 0) {
                dpTriPost[i] = dpTriPre[i-1] + triangle[i][i];
            }
            dpTriPre = dpTriPost;
        }
        int minValue = INT32_MAX;
        for (int i = 0; i < triangle.size(); ++i) {
            if (dpTriPost[i] < minValue) minValue = dpTriPost[i];
        }
        return minValue;
    }
};

int main() {
    Solution s;
    return 0;
}

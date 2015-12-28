#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int row = searchRow(matrix, target);
        if (row == -1) return false;
        return searchCol(matrix[row], target);
    }

    int searchRow(vector<vector<int>> &matrix, int target) {
        int lo = 0, hi = matrix.size() - 1;
        int mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (matrix[mi][0] == target) return mi;
            if (matrix[mi][0] < target) lo = mi + 1;
            else hi = mi - 1;
        }
        // return the position before insertion
        return lo - 1;  // in range [-1, matrix.size()-1]
    }

    bool searchCol(vector<int> &vec, int target) {
        int lo = 0, hi = vec.size() - 1;
        int mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (vec[mi] == target) return true;
            if (vec[mi] < target) lo = mi + 1;
            else hi = mi - 1;
        }
        return false;
    }
};

int main() {
    Solution s;
	return 0;
}

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int nrow = matrix.size();
        if (nrow == 0) {
            return 0;
        }
        int ncol = matrix[0].size();
        if (ncol == 0) {
            return 0;
        }
        int row = 0;
        int col = ncol-1;
        int count = 0;
        while (row <= nrow-1 && col >= 0) {
            if (matrix[row][col] == target) {
                ++count;
                ++row;
            } else if (matrix[row][col] > target) {
                --col;
            } else if (matrix[row][col] < target) {
                ++row;
            }
        }
        return count;
    }
};
 

int main() {
    vector<int> row1 = vector<int>();
    row1.push_back(1);
    row1.push_back(2);
    vector<int> row2 = vector<int>();
    row2.push_back(2);
    row2.push_back(4);
    vector<vector<int> > mat = vector<vector<int> >();
    mat.push_back(row1);
    mat.push_back(row2);
    
    Solution s;
    cout << s.searchMatrix(mat, 2) << endl;
	return 0;
}

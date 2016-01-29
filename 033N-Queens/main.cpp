#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> allSolutions;
        vector<string> solution;
        vector<int> locations;
        solveNQ(allSolutions, solution, locations, n, 0);
        return allSolutions;
    }

    void solveNQ(vector<vector<string>> &all, vector<string> &sln, vector<int> &line, int n, int row) {
        // a solution is found
        if (row == n) {
            all.push_back(sln);
            return;
        }
        // finding a solution for current row
        for (int col = 0; col < n; ++col) {
            if (validPos(line, row, col)) {
                line.push_back(col);
                string colRepr(n, '.');
                colRepr[col] = 'Q';
                sln.push_back(colRepr);
                solveNQ(all, sln, line, n, row+1);
                sln.pop_back();
                line.pop_back();
            }
        }
    }

    bool validPos(vector<int> line, int row, int col) {
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == col) return false;
            if (i - line[i] == row - col) return false;
            if (i + line[i] == row + col) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

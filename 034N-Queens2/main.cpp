#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        vector<vector<int>> allSolutions;
        vector<int> solution;
        solveNQ(allSolutions, solution, n);
        return allSolutions.size();
    }

    void solveNQ(vector<vector<int>> &all, vector<int> &sol, int n) {
        if (sol.size() == n) {
            all.push_back(sol);
            return;
        }
        int row = sol.size();
        for (int i = 0; i < n; ++i) {
            if (!legalPos(sol, row, i)) continue;
            sol.push_back(i);
            solveNQ(all, sol, n);
            sol.pop_back();
        }
    }

    bool legalPos(vector<int> &sol, int row, int col) {
        for (int i = 0; i < sol.size(); ++i) {
            if (sol[i] == col) return false;
            if (i + sol[i] == row + col) return false;
            if (row + sol[i] == col + i) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> mask(m, vector<char>(n, 'X'));
        for (int j = 0; j < n; ++j) {
            dfs(board, mask, 0, j);
            dfs(board, mask, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            dfs(board, mask, i, 0);
            dfs(board, mask, i, n-1);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = mask[i][j];
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<char>>& mask, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || row >= m) return;
        if (col < 0 || col >= n) return;
        if (board[row][col] == 'O' && mask[row][col] == 'X') {
            mask[row][col] = 'O';
            dfs(board, mask, row-1, col);
            dfs(board, mask, row+1, col);
            dfs(board, mask, row, col-1);
            dfs(board, mask, row, col+1);
        }
    }
};

int main() {
    Solution s;
    return 0;
}

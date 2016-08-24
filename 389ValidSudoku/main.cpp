#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        // assume the board is 9x9
        // check each row
        for (int i = 0; i < 9; ++i) {
            set<int> numbers;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (board[i][j] < '1' || board[i][j] > '9') {
                        return false;
                    }
                    if (numbers.find(board[i][j]) != numbers.end()) {
                        return false;
                    }
                    numbers.insert(board[i][j]);
                }
            }
        }
        // check each column
        for (int j = 0; j < 9; ++j) {
            set<int> numbers;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (board[i][j] < '1' || board[i][j] > '9') {
                        return false;
                    }
                    if (numbers.find(board[i][j]) != numbers.end()) {
                        return false;
                    }
                    numbers.insert(board[i][j]);
                }
            }
        }
        // check for small box
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                set<int> numbers;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        int r = 3*i+k;
                        int c = 3*j+l;
                        if (board[r][c] != '.') {
                            if (board[r][c] < '1' || board[r][c] > '9') {
                                return false;
                            }
                            if (numbers.find(board[r][c]) != numbers.end()) {
                                return false;
                            }
                            numbers.insert(board[r][c]);
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) return true;
        char c0 = word[0];
        vector<vector<int>> coord;
        set<vector<int>> visited;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == c0) {
                    vector<int> p = {i, j};
                    coord.push_back(p);
                }
            }
        }
        for (auto p: coord) {
            visited.insert(p);
            bool res = exist(board, string(word.begin()+1, word.end()), p[0], p[1], visited);
            visited.erase(p);
            if (res) return true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word, int row, int col, set<vector<int>>& visited) {
        if (word.empty()) return true;
        char c = word[0];
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> coord;
        if (row > 0 && board[row-1][col] == c) {
            vector<int> p = {row-1, col};
            if (visited.find(p) == visited.end())
                coord.push_back(p);
        }
        if (row + 1 < m && board[row+1][col] == c) {
            vector<int> p = {row+1, col};
            if (visited.find(p) == visited.end())
                coord.push_back(p);
        }
        if (col > 0 && board[row][col-1] == c) {
            vector<int> p = {row, col-1};
            if (visited.find(p) == visited.end())
                coord.push_back(p);
        }
        if (col + 1 < n && board[row][col+1] == c) {
            vector<int> p = {row, col+1};
            if (visited.find(p) == visited.end())
                coord.push_back(p);
        }
        for (auto p: coord) {
            visited.insert(p);
            bool res = exist(board, string(word.begin()+1, word.end()), p[0], p[1], visited);
            visited.erase(p);
            if (res) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class LineReg {
public:
    LineReg() {};
    LineReg(int n, int r, int c):
        number(n), row(r), col(c) {}
    int number;
    int row;
    int col;
    // NOTE: by default priority_queue makes a max heap
    // we need to overwrite to make a min heap
    bool operator() (const LineReg& lhs, const LineReg& rhs) {
        return (lhs.number > rhs.number);
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // assume the matrix is not empty
        int m = matrix.size();
        int n = matrix[0].size();
        int cnt = 0;
        priority_queue<LineReg, vector<LineReg>, LineReg> queue;
        for (int i = 0; i < m; ++i) {
            queue.push(LineReg(matrix[i][0], i, 0));
        }
        while (true) {
            LineReg elem = queue.top();
            queue.pop();
            ++cnt;
            if (cnt == k) return elem.number;
            else {
                if (elem.col < n-1)
                    queue.push(LineReg(matrix[elem.row][elem.col+1], elem.row, elem.col+1));
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> data = {{1, 5, 7}, {3, 7, 8}, {4, 8, 9}};
    cout << s.kthSmallest(data, 4) << endl;
    return 0;
}

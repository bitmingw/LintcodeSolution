#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        if (!L.size()) return 0;
        sort(L.begin(), L.end());
        int lo_len = 1, hi_len = L[L.size()-1];
        int mi_len, num_piece;
        while (lo_len <= hi_len) {
            mi_len = lo_len + (hi_len - lo_len) / 2;
            num_piece = countPieces(L, mi_len);
            if (num_piece == k && countPieces(L, mi_len+1) < k) return mi_len;
            if (num_piece >= k) lo_len = mi_len + 1;
            else hi_len = mi_len - 1;
        }
        // here we should have lo_len > hi_len
        return hi_len;
    }

    int countPieces(vector<int> &vec, int len) {
        int count = 0;
        for (int i = 0; i < vec.size(); ++i) {
            count += vec[i] / len;
        }
        return count;
    }
};

int main() {
    Solution s;
	return 0;
}

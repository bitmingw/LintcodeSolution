#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/

class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        if (nuts.empty()) return;
        quicksort(nuts, bolts, 0, nuts.size()-1, compare);
    }

    void quicksort(vector<string>& nuts, vector<string>& bolts, int begin, int end, Comparator cmp) {
        if (begin >= end) return;
        int pivot_pos;
        int left = 0;
        for (int i = begin; i <= end; ++i) {
            int res = cmp.cmp(nuts[begin], bolts[i]);
            if (res == 0) {
                // find the corresponding place for bolt
                pivot_pos = i;
            } else if (res == 1) {
                // find number of smaller bolts
                ++left;
            }
        }
        // put pivot into position
        swap(nuts, begin, begin+left);
        swap(bolts, pivot_pos, begin+left);
        pivot_pos = begin + left;
        // do mutual quicksort
        int i = begin, j = end;
        while (i < pivot_pos && pivot_pos < j) {
            while (i < pivot_pos && cmp.cmp(nuts[pivot_pos], bolts[i]) == 1) ++i;
            while (j > pivot_pos && cmp.cmp(nuts[pivot_pos], bolts[j]) == -1) --j;
            if (i < j) {
                swap(bolts, i, j);
                ++i;
                --j;
            }
        }
        i = begin, j = end;
        while (i < pivot_pos && pivot_pos < j) {
            while (i < pivot_pos && cmp.cmp(nuts[i], bolts[pivot_pos]) == -1) ++i;
            while (j > pivot_pos && cmp.cmp(nuts[j], bolts[pivot_pos]) == 1) --j;
            if (i < j) {
                swap(nuts, i, j);
                ++i;
                --j;
            }
        }
        quicksort(nuts, bolts, begin, pivot_pos-1, cmp);
        quicksort(nuts, bolts, pivot_pos+1, end, cmp);
    }

    void swap(vector<string>& sth, int idx1, int idx2) {
        string tmp = sth[idx1];
        sth[idx1] = sth[idx2];
        sth[idx2] = tmp;
    }
};

int main() {
    Solution s;
    return 0;
}

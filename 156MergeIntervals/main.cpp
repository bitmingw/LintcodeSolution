#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

// NOTE: the comp function must be outside the class
bool sortStart(Interval& a, Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> merged;
        // sort the intervals in order
        merged = intervals;
        sort(merged.begin(), merged.end(), sortStart);
        // deal with the corner cases
        if (merged.empty() || merged.size() == 1) return merged;
        // check the overlaps
        for (int i = 1; i < merged.size(); ++i) {
            if (merged[i].start <= merged[i-1].end) {
                merged[i-1].end = max(merged[i-1].end, merged[i].end);
                merged.erase(merged.begin() + i);
                --i;
            }
        }
        return merged;
    }
};

int main() {
    Solution s;
    return 0;
}

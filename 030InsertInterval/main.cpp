#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // find the place to insert
        int pos = intervals.size();
        if (pos == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (unsigned int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start >= newInterval.end) {
                pos = i;
                break;
            }
        }
        auto it = intervals.begin();
        intervals.insert(it + pos, newInterval);
        // merge the intervals
        while (mergeInterval(intervals));
        return intervals;
    }

    bool mergeInterval(vector<Interval> &intervals) {
        bool hasMerge = false;
        auto it = intervals.begin();
        for (unsigned int i = 0; i + 1 < intervals.size(); ++i) {
            if (intervals[i].end >= intervals[i+1].start) {
                intervals[i].start = min(intervals[i].start, intervals[i+1].start);
                intervals[i].end = max(intervals[i].end, intervals[i+1].end);
                intervals.erase(it + i + 1);
                --i;
                hasMerge = true;
            }
        }
        return hasMerge;
    }
};

int main() {
    Solution s;
	return 0;
}

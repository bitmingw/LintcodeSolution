#include <vector>
#include <iostream>
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
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        if (airplanes.empty()) return 0;
        int len = airplanes.size();
        vector<int> enter_times;
        vector<int> exit_times;
        for (auto interval: airplanes) {
            enter_times.push_back(interval.start);
            exit_times.push_back(interval.end);
        }
        sort(enter_times.begin(), enter_times.end());
        sort(exit_times.begin(), exit_times.end());
        int max_num = 0;
        int cur_num = 0;
        int enter_idx = 0;
        int exit_idx = 0;
        while (enter_idx <= len) {
            if (enter_idx == len) {
                cur_num = enter_idx - exit_idx;
                if (cur_num > max_num) max_num = cur_num;
                break;
            } else {
                if (enter_times[enter_idx] < exit_times[exit_idx]) {
                    ++enter_idx;
                } else if (enter_times[enter_idx] > exit_times[exit_idx]) {
                    ++exit_idx;
                } else {
                    ++enter_idx;
                    ++exit_idx;
                }
                cur_num = enter_idx - exit_idx;
                if (cur_num > max_num) max_num = cur_num;
            }
        }
        return max_num;
    }
};

int main() {
    Solution s;
	return 0;
}

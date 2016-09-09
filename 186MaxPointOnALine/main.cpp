#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        if (points.size() == 1) return 1;
        if (points.size() == 2) return 2;
        int max_lines = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<float, int> records;
            int duplicates = 1;
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicates;
                    continue;
                }
                float k;
                if (points[i].x == points[j].x) {
                    k = INT32_MAX;
                } else {
                    k = (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                records[k]++;
            }
            if (records.empty() && duplicates > max_lines)
                max_lines = duplicates;
            for (auto it = records.begin(); it != records.end(); ++it) {
                if (it->second + duplicates > max_lines)
                    max_lines = it->second + duplicates;
            }
        }
        return max_lines;
    }
};

int main() {
    Solution s;
    vector<Point> data = {Point(1, 2), Point(3, 6), Point(1, 3), Point(0, 0)};
    cout << s.maxPoints(data) << endl;  // should be 3
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // dynamic programming
        // go through s1 & s2 on each possible path
        queue<vector<int>> track;
        track.push(vector<int>(2, 0));
        vector<int> location;
        int steps = 0;
        while (!track.empty()) {
            location = track.front();
            track.pop();
            steps = location[0] + location[1];
            if (location[0] == s1.size() && location[1] == s2.size() && steps == s3.size())
                return true;
            if (location[0] < s1.size() && s1[location[0]] == s3[steps]) {
                ++location[0];
                track.push(location);
                --location[0];
            }
            if (location[1] < s2.size() && s2[location[1]] == s3[steps]) {
                ++location[1];
                track.push(location);
                --location[1];
            }
        }
        return false;
    }
};

int main() {
    Solution s;
	return 0;
}

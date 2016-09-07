#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        if (ratings.size() == 1) return 1;
        vector<int> candies(ratings.size(), 1);
        while (true) {
            bool satisfied = true;
            for (int i = 0; i < ratings.size(); ++i) {
                if (i == 0) {
                    if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                        satisfied = false;
                        candies[i] = candies[i+1] + 1;
                    }
                } else if (i == ratings.size() - 1) {
                    if (ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
                        satisfied = false;
                        candies[i] = candies[i-1] + 1;
                    }
                } else {
                    if (ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]) {
                        satisfied = false;
                        candies[i] = candies[i-1] + 1;
                    }
                    if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                        satisfied = false;
                        candies[i] = candies[i+1] + 1;
                    }
                }
            }
            if (satisfied) break;
        }
        int sum = 0;
        for (int num: candies) {
            sum += num;
        }
        return sum;
    }
};

int main() {
    Solution s;
    return 0;
}

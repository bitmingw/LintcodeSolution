#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        height.push_back(0);  // ending period
        stack<int> s;
        int max_val = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[i] >= height[s.top()])
                s.push(i);
            else {
                int max_height = height[s.top()];
                while (max_height > height[i]) {
                    s.pop();
                    int width = s.empty() ? i : i - s.top() - 1;
                    max_val = max(max_val, max_height * width);
                    if (s.empty()) break;
                    max_height = height[s.top()];
                }
                s.push(i);
            }
        }
        return max_val;
    }
};

int main() {
    Solution s;
    vector<int> data = {5, 4, 1, 2};
    s.largestRectangleArea(data);
    return 0;
}

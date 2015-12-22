#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        if (n >= 3) {
            for (int c = 2; c <= n-1; ++c) {
                arr.push_back(arr[c-2] + arr[c-1]);
            }
        }
        return arr[n-1];
    }
};

int main() {
	Solution s = Solution();
    cout << "Input: 1. Output: " << s.fibonacci(1) << endl;
    cout << "Input: 10. Output: " << s.fibonacci(10) << endl;
	return 0;
}

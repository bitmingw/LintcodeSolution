#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
        for (int i = 0; i < sizeof(int)*8; ++i) {
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }
};  

int main() {
	Solution s = Solution();
    cout << s.countOnes(32) << endl;
    cout << s.countOnes(5) << endl;
    cout << s.countOnes(1023) << endl;
	return 0;
}

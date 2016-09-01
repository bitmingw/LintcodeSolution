#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        if (num == 2) return true;
        if (num == 3) return true;
        if (num == 5) return true;
        if (num % 2 == 0) {
            return isUgly(num / 2);
        }
        if (num % 3 == 0) {
            return isUgly(num / 3);
        }
        if (num % 5 == 0) {
            return isUgly(num / 5);
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long> uglyList  = vector<long long>();
        uglyList.push_back(3);
        uglyList.push_back(5);
        uglyList.push_back(7);
        int p3 = 0, p5 = 0, p7 = 0; // pointer to smallest possible number
        long long next = 0;
        while (static_cast<unsigned int>(k) > uglyList.size()) {
            next = min(uglyList[p3]*3, uglyList[p5]*5);
            next = min(next, uglyList[p7]*7);
            uglyList.push_back(next);
            if (next / 3 == uglyList[p3] && next % 3 == 0) ++p3;
            if (next / 5 == uglyList[p5] && next % 5 == 0) ++p5;
            if (next / 7 == uglyList[p7] && next % 7 == 0) ++p7;
        }
        return uglyList[k-1];
    }
};

int main() {
    Solution s;
    cout << s.kthPrimeNumber(4) << endl; // should be 9
    return 0;
}

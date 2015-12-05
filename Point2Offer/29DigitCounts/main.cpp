#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        vector<int> countTable = vector<int>(10, 0);
        string num_repr;
        for (int i = 0; i <= n; ++i) {
            num_repr = to_string(i);
            for (string::iterator it = num_repr.begin(); it != num_repr.end(); ++it) {
                ++countTable[*it - '0'];
            }
        }
        return countTable[k];
    }
};

int main() {
    Solution s;
    cout << s.digitCounts(1, 12) << endl; // should be 5
    return 0;
}

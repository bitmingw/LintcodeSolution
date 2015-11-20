#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> result = vector<int>();
        appendRecur(result, n, 0);
        return result;
    }
    
    void appendRecur(vector<int>& vec, int n, int start_idx) {
        if (n == 0) {
            return;
        }
        int size = vec.size();
        if (size == 0) {
            for (int i = 1; i < 10; ++i) {
                vec.push_back(i);
            }
            appendRecur(vec, n-1, 0);
        } else {
            for (int i = start_idx; i < size; ++i) {
                for (int j = 0; j < 10; ++j) {
                    vec.push_back(10*vec[i]+j);
                }
            }
            appendRecur(vec, n-1, size);
        }
    }
};


int main() {
    Solution s;
    vector<int> printed = s.numbersByRecursion(3);
    for (vector<int>::iterator it = printed.begin(); it != printed.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

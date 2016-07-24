#include <vector>
#include <iostream>
using namespace std;

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        if (A.empty()) return false;
        for (int val: A) {
            if (val == target) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

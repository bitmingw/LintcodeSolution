#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        string a(A);
        string b(B);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return !a.compare(b);
    }
};



int main() {
    Solution s;
    string a1 = "abcd", b1 = "acbd", a2 = "abbe", b2 = "abe";
    cout << s.stringPermutation(a1, b1) << endl;  // true
    cout << s.stringPermutation(a2, b2) << endl;  // false
    return 0;
}

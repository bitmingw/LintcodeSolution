#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str, int offset){
        if (!str.length() || offset <= 0) return;
        offset %= str.length();
        reverseStr(str, 0, str.length()-1);
        reverseStr(str, 0, offset-1);
        reverseStr(str, offset, str.length()-1);
    }
    
    void reverseStr(string& str, int b, int e) {
        char tmp;
        while (b < e) {
            tmp = str[b];
            str[b] = str[e];
            str[e] = tmp;
            ++b;
            --e;
        }
    }
};

int main() {
    Solution s;
    string str = "abcdefg";
    s.rotateString(str, 3);
    cout << str << endl;  // should be efgabcd
    return 0;
}

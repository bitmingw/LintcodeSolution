#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // move lower case letters to the front
        // and upper case letters to the back
        int len = letters.size();
        int front = 0;
        int back = len - 1;
        while (true) {
            if (front > back) break;
            else if (islower(letters[front])) ++front;
            else if (isupper(letters[back])) --back;
            else {
                char tmp = letters[front];
                letters[front] = letters[back];
                letters[back] = tmp;
                ++front;
                --back;
            }
        }
    }
};

int main() {
    Solution s;
    string str1 = "abAcD";
    s.sortLetters(str1);
    cout << str1 << endl;  // should be "abcAD"
    return 0;
}

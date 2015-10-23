#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        // Scan and calculate number of spaces
        int space_pos = 0;
        for (int idx = 0; idx < length; ++idx) {
            if (string[idx] == ' ') {
                ++space_pos;
            }
        }
        
        // Do replacement
        char *new_s = new char[length+1];
        strncpy(new_s, string, length);
        int old_idx = 0;
        int new_idx = 0;
        while (new_idx < length) {
            if (new_s[new_idx] != ' ') {
                string[old_idx] = new_s[new_idx];
                ++old_idx;
                ++new_idx;   
            } else {
                string[old_idx] = '%';
                string[old_idx+1] = '2';
                string[old_idx+2] = '0';
                old_idx += 3;
                ++new_idx;
            }
        }
        
        return length+2*space_pos;
    }
};  

int main() {
	Solution s = Solution();
    char test[10];
    test[0] = 'M';
    test[1] = 'r';
    test[2] = ' ';
    int length = 3;
    cout << s.replaceBlank(test, length) << endl;
	return 0;
}

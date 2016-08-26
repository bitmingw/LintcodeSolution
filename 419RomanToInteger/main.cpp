#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // 1 <= res <= 3999
        int thousand = 0, hundred = 0, ten = 0, one = 0;
        int n = s.length();
        int p = 0;
        while (p < n && s[p] == 'M') {
            thousand += 1;
            ++p;
        }
        if (p + 1 < n && s[p] == 'C' && s[p+1] == 'M') {
            hundred = 9;
            p += 2;
        } else if (p + 1 < n && s[p] == 'C' && s[p+1] == 'D') {
            hundred = 4;
            p += 2;
        } else if (p < n && s[p] == 'D') {
            hundred = 5;
            ++p;
        }
        while (p < n && s[p] == 'C') {
            hundred += 1;
            ++p;
        }
        if (p + 1 < n && s[p] == 'X' && s[p+1] == 'C') {
            ten = 9;
            p += 2;
        } else if (p + 1 < n && s[p] == 'X' && s[p+1] == 'L') {
            ten = 4;
            p += 2;
        } else if (p < n && s[p] == 'L') {
            ten = 5;
            ++p;
        }
        while (p < n && s[p] == 'X') {
            ten += 1;
            ++p;
        }
        if (p + 1 < n && s[p] == 'I' && s[p+1] == 'X') {
            one = 9;
            p += 2;
        } else if (p + 1 < n && s[p] == 'I' && s[p+1] == 'V') {
            one = 4;
            p += 2;
        } else if (p < n && s[p] == 'V') {
            one = 5;
            ++p;
        }
        while (p < n && s[p] == 'I') {
            one += 1;
            ++p;
        }
        return thousand * 1000 + hundred * 100 + ten * 10 + one;
    }
};

int main() {
    Solution s;
    return 0;
}

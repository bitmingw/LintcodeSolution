#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        bool sign = false, neg = false, trun = false, space = false;
        bool invalid = false, number = false;
        int trunPos = -1, signPos = -1;
        for (int i = 0; i < str.length(); ++i) {
            if (!number && str[i] == ' ') { // leading spaces
                space = true;
                signPos = i;
            } else if (number && str[i] == ' ') { // trailing spaces
                trun = true;
                trunPos = i;
                break;
            } else if (!sign && !number && str[i] == '-') {
                sign = true;
                neg = true;
                signPos = i;
            } else if (!sign && !number && str[i] == '+') {
                sign = true;
                signPos = i; 
            } else if (!trun && str[i] == '.') {
                trun = true;
                trunPos = i;
                break;
            } else if (str[i] >= '0' && str[i] <= '9') {
                number = true;
            } else if (number) { // invalid but already has number
                trun = true;
                trunPos = i;
                break;
            } else { // invalid and no number
                invalid = true;
                break;
            }
        }
        if (invalid) return 0;
        if (trun || sign || space) str = string(str, signPos+1, trunPos - signPos - 1);
        unsigned int num = 0;
        int digit = 0, pos = str.length()-1, ipos = 0;
        while (pos >= 0) {
            digit = str[pos] - '0';
            //cout << digit << " " << num << " " << pos << " " << ipos << endl;
            if (ipos >= 9 && !neg) return 2147483647;
            if (ipos >= 9 && neg) return -2147483648;
            if (ipos == 8 && digit >= 2 && (!neg && num > 147483647))
                return 2147483647;
            if (ipos == 8 && digit >= 2 && (neg && num > 147483648))
                return -2147483648;
            num += digit * pow(10, ipos);
            ++ipos;
            --pos;
        }
        //cout << num << " " << static_cast<int>(num) << endl;
        if (neg && num == 2147483648) return -2147483648;
        else if (neg) return 0 - static_cast<int>(num);
        else return static_cast<int>(num);
    }
    
    int pow(int base, int index) {
        int num = 1;
        for (int i = 0; i < index; ++i) {
            num *= base;
        }
        return num;
    }
};

int main() {
    Solution s;
    
    cout << s.atoi("-1") << endl;  // should be -1
    cout << s.atoi("2147483647") << endl;  // should be 2147483647
    cout << s.atoi("2147483648") << endl;  // should be 2147483647
    cout << s.atoi("-2147483648") << endl;  // should be -2147483648
    cout << s.atoi("1.0") << endl;  // should be 1
    cout << s.atoi("    -5211314 ") << endl;  // should be -5211314
    cout << s.atoi("  52lintcode  ") << endl;  // should be 52
    cout << s.atoi("   010") << endl;  // should be 10
    cout << s.atoi(" 15+4") << endl;  // should be 15
    return 0;
}

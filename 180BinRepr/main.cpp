#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        // assume the input is always valid and no negative number
        // explicit split the string into two parts and then convert
        // to make sure the accuracy is not lost
        int decimalPos = -1;
        for (int i = 0; i < n.length(); ++i) {
            if (n[i] == '.') {
                decimalPos = i;
                break;
            }
        }
        string wholeDec(n.begin(), n.begin()+decimalPos);
        string fragDec(n.begin()+decimalPos+1, n.end());
        fragDec.insert(0, "0.");
        int whole = atoi(wholeDec.c_str());
        double frag = atof(fragDec.c_str());
        // cout << whole << " " << frag << endl;
        string wholeStr = binReprWhole(whole);
        string fragStr = binReprFrag(frag);
        if (fragStr != "ERROR") {
            if (!wholeStr.length() && !fragStr.length()) return "0";
            if (!wholeStr.length()) return "0." + fragStr;
            if (!fragStr.length()) return wholeStr;
            return wholeStr + "." + fragStr;
        }
        else return "ERROR";
    }

    string binReprWhole(int num) {
        string binStr = "";
        int bit;
        while (num) {
            bit = num % 2;
            if (bit == 0) binStr += '0';
            if (bit == 1) binStr += '1';
            num /= 2;
        }
        // reverse the string
        char tmp;
        for (int i = 0, j = binStr.length()-1; i < j; ++i, --j) {
            tmp = binStr[i];
            binStr[i] = binStr[j];
            binStr[j] = tmp;
        }
        return binStr;
    }

    string binReprFrag(double num) {
        // this number should be in range of 0 - 1
        string binStr = "";
        int bit;
        while (num) {
            num *= 2;
            bit = static_cast<int>(num);
            if (bit == 0) binStr += '0';
            if (bit == 1) binStr += '1';
            num -= bit;
            if (binStr.length() > 32) return "ERROR";
        }
        return binStr;
    }
};

int main() {
    Solution s;
    cout << s.binaryRepresentation("3.72") << endl;  // should be ERROR
    cout << s.binaryRepresentation("3.5") << endl;  // should be 11.1
    cout << s.binaryRepresentation("28187281.128121212121") << endl;  // should be ERROR
    return 0;
}

#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool sortStr(string i, string j) {
    string ij = i + j;
    string ji = j + i;
    return ij.compare(ji) < 0;
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        vector<string> numStr;
        char n[12];
        for (int i = 0; i < num.size(); ++i) {
            sprintf(n, "%d", num[i]);
            numStr.push_back(string(n));
        }
        sort(numStr.begin(), numStr.end(), sortStr);
        string result;
        for (int i = numStr.size()-1; i >= 0; --i) {
            result += numStr[i];
        }
        // special case: remove fronting zeros
        if (result[0] == '0') return "0";
        return result;
    }
};

int main() {
    Solution s;
    int arr[] = {1, 23, 20, 8, 4};
    vector<int> vec(arr, arr+5);
    cout << s.largestNumber(vec) << endl;  // should be 8423201
    return 0;
}

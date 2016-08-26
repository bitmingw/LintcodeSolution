#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        string pre = "1";
        string cur;
        int round = 1;
        while (round < n) {
            cur = "";
            int n = pre.length();
            int p = 0;
            int pre_num = -1;
            int cur_num;
            int cnt = 0;
            while (p < n) {
                cur_num = stoi(string(1, pre[p]));
                if (cur_num != pre_num) {
                    if (pre_num == -1) {
                        pre_num = cur_num;
                        cnt = 1;
                    } else {
                        cur += to_string(cnt);
                        cur += to_string(pre_num);
                        pre_num = cur_num;
                        cnt = 1;
                    }
                } else {
                    cnt += 1;
                }
                ++p;
            }
            cur += to_string(cnt);
            cur += to_string(cur_num);
            pre = cur;
            ++round;
        }
        return cur;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    return 0;
}

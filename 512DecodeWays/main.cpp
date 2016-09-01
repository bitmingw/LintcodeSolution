#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        if (s.empty()) return 0;
        if (s.size() == 1) {
            int num = stoi(s);
            if (num >= 1 && num <= 9) return 1;
            else return 0;
        } else {
            vector<int> start_num(s.size(), 0);
            int num1 = stoi(string(s.end()-1, s.end()));
            if (num1 >= 1 && num1 <= 9) {
                start_num[s.size()-1] = 1;
            }
            int num2 = stoi(string(s.end()-2, s.end()));
            if (num2 >= 10 && num2 <= 26) {
                start_num[s.size()-2] = start_num[s.size()-1] + 1;
            } else if (num2 >= 27 && num2 <= 99) {
                start_num[s.size()-2] = start_num[s.size()-1];
            }
            for (int i = s.size()-3; i >= 0; --i) {
                num1 = stoi(string(s.begin()+i, s.begin()+i+1));
                if (num1 >= 1 && num1 <= 9) {
                    start_num[i] += start_num[i+1];
                }
                num2 = stoi(string(s.begin()+i, s.begin()+i+2));
                if (num2 >= 10 && num2 <= 26) {
                    start_num[i] += start_num[i+2];
                }
            }
            return start_num[0];
        }
    }
};

int main() {
    Solution s;
    string data = "2226252724242221201918171615141311108787876761721201211012111989898911918293";
    cout << s.numDecodings(data) << endl;
    return 0;
}

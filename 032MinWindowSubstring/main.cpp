#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        if (source.empty() || target.empty()) return string();
        map<char, int> smap, tmap;
        int solution_len = INT32_MAX;
        string solution;
        for (int i = 0; i < target.size(); ++i) {++tmap[target[i]];}
        int head = 0, tail = 0;
        while (tail < source.size()) {
            ++smap[source[tail]];
            ++tail;
            if (hasCovered(smap, tmap)) {
                while (head < tail) {
                    --smap[source[head]];
                    ++head;
                    if (!hasCovered(smap, tmap)) {
                        --head;
                        ++smap[source[head]];
                        break;
                    }
                }
                if (tail - head < solution_len) {
                    solution = string(source.begin() + head, source.begin() + tail);
                    solution_len = tail - head;
                }
            }
        }
        return solution;
    }

    bool hasCovered(map<char, int> s, map<char, int> t) {
        for (auto t_it = t.begin(); t_it != t.end(); ++t_it) {
            if (s.find(t_it->first) == s.end() || s[t_it->first] < t_it->second) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

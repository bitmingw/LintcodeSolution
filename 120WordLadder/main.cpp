#include <iostream>
#include <unordered_set>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        queue<pair<string, int>> q;
        string word = start;
        int transLen = 1;
        vector<string> trans = transWord(word, dict);
        for (int i = 0; i < trans.size(); ++i) {
            q.push(make_pair(trans[i], transLen + 1));
        }
        while (!q.empty()) {
            word = q.front().first;
            transLen = q.front().second;
            q.pop();
            if (word == end) return transLen;
            trans = transWord(word, dict);
            for (int i = 0; i < trans.size(); ++i) {
                q.push(make_pair(trans[i], transLen + 1));
            }
        }
        return 0;
    }

    vector<string> transWord(string word, unordered_set<string> &dict) {
        vector<string> li;
        string w;
        for (int i = 0; i < word.size(); ++i) {
            w = word;
            for (char j = 'a'; j <= 'z'; ++j) {
                w[i] = j;
                if (w != word && dict.find(w) != dict.end()) {
                    dict.erase(w);
                    li.push_back(w);
                }
            }
        }
        return li;
    }
};

int main() {
    Solution s;
    return 0;
}

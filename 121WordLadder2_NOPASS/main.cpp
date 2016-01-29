#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ladders;
        queue<vector<string>> searchQ;
        dict.insert(end);
        vector<string> path;
        path.push_back(start);
        searchQ.push(path);
        updateLadders(ladders, searchQ, dict, end);
        return ladders;
    }

    void updateLadders(vector<vector<string>> &ladders, queue<vector<string>> &searchQ, unordered_set<string> &dict, string end) {
        while (!searchQ.empty()) {
            vector<string> path = searchQ.front();
            searchQ.pop();
            if (!ladders.empty() && path.size() > ladders.back().size()) return;
            if (path.back() == end) {
                if (ladders.empty() || path.size() == ladders.back().size())
                ladders.push_back(path);
            }
            vector<string> options = genChanges(path.back());
            unordered_set<string> pathSet(path.begin(), path.end());
            for (auto op_it = options.begin(); op_it != options.end(); ++op_it) {
                if (pathSet.find(*op_it) == pathSet.end() && dict.find(*op_it) != dict.end()) {
                    path.push_back(*op_it);
                    searchQ.push(path);
                    path.pop_back();
                }
            }
        }
    }

    vector<string> genChanges(string origin) {
        vector<string> changes;
        for (int i = 0; i < origin.size(); ++i) {
            string s(origin);
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != origin[i]) {
                    s[i] = c;
                    changes.push_back(s);
                }
            }
        }
        return changes;
    }
};

int main() {
    Solution s;
    return 0;
}

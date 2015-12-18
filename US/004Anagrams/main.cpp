#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    // We may assume elements in input list are distinct
    vector<string> anagrams(vector<string> &strs) {
        vector<string> anagrams;
        if (strs.size() < 2) return anagrams;
        // make a vector to track the inserted strings
        vector<bool> inserted = vector<bool>(strs.size(), 0);
        // make a copy of original input
        vector<string> sorted_strs(strs);
        // sort each string in the vector
        for (int i = 0; i < sorted_strs.size(); ++i) {
            sort(sorted_strs[i].begin(), sorted_strs[i].end());
        }
        // compare the strings
        for (int i = 0; i < sorted_strs.size()-1; ++i) {
            for (int j = i+1; j < sorted_strs.size(); ++j) {
                if (!strcmp(sorted_strs[i].c_str(), sorted_strs[j].c_str())) {
                    if (!inserted[i]) {
                        anagrams.push_back(strs[i]);
                        inserted[i] = true;
                    }
                    if (!inserted[j]) {
                        anagrams.push_back(strs[j]);
                        inserted[j] = true;
                    }
                }
            }
        }
        return anagrams;
    }
};

int main() {
    Solution s;
    return 0;
}

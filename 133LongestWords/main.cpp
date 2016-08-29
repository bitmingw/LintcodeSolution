#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        int max_len = -1;
        vector<string> long_words;
        if (dictionary.empty()) return long_words;
        long_words.push_back(dictionary[0]);
        max_len = dictionary[0].length();
        for (int i = 1; i < dictionary.size(); ++i) {
            if (dictionary[i].length() > max_len) {
                long_words.clear();
                max_len = dictionary[i].length();
            }
            if (dictionary[i].length() == max_len)
                long_words.push_back(dictionary[i]);
        }
        return long_words;
    }
};

int main() {
    Solution s;
    return 0;
}

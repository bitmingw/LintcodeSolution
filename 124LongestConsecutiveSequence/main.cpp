#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) return 0;
        unordered_set<int> collection;
        for (int n: num) {
            collection.insert(n);
        }

        int lcs = 1;
        for (int n: num) {
            int len = 0;
            if (collection.find(n) != collection.end()) {
                len += 1;
                collection.erase(n);
                int i = 1;
                while (collection.find(n-i) != collection.end()) {
                    len += 1;
                    collection.erase(n-i);
                    ++i;
                }
                i = 1;
                while (collection.find(n+i) != collection.end()) {
                    len += 1;
                    collection.erase(n+i);
                    ++i;
                }
            }
            if (len > lcs) lcs = len;
        }
        return lcs;
    }
};

int main() {
    Solution s;
    return 0;
}

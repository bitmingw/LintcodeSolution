#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> flat;
        for (auto elem: nestedList) {
            if (elem.isInteger()) {
                flat.push_back(elem.getInteger());
            } else {
                vector<NestedInteger> subList = elem.getList();
                vector<int> nestedFlat = flatten(subList);
                for (int num: nestedFlat) {
                    flat.push_back(num);
                }
            }
        }
        return flat;
    }
};

int main() {
    Solution s;
    return 0;
}

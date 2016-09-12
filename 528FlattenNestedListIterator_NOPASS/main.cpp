#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
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

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        li = vector<NestedInteger>(nestedList.begin(), nestedList.end());
        len = nestedList.size();
        pos = 0;
    }

    // @return {int} the next element in the iteration
    int next() {
        if (li[pos].isInteger()) {
            ++pos;
            return li[pos-1].getInteger();
        } else {
            if (!subiter) {
                const vector<NestedInteger>& subList = li[pos].getList();
                subiter = new NestedIterator(subList);
                if (subiter->hasNext()) return subiter->next();
                else {
                    delete subiter;
                    subiter = NULL;
                    ++pos;
                    return this->next();
                }
            } else {
                if (subiter->hasNext()) return subiter->next();
                else {
                    delete subiter;
                    subiter = NULL;
                    ++pos;
                    return this->next();
                }
            }
        }
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        return len != pos;
    }

private:
    vector<NestedInteger> li;
    NestedIterator* subiter;
    int len;
    int pos;
};

int main() {
    return 0;
}

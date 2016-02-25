#include <iostream>
#include <vector>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = new ListNode(0);  // dummy
        ListNode *cur = head;
        int nlist = lists.size();
        while (true) {
            // exit condition
            if (allNull(lists)) break;
            // find min
            int minIdx = -1, minValue = INT32_MAX;
            for (int i = 0; i < nlist; ++i) {
                if (!lists[i]) continue;
                if (lists[i]->val < minValue) {
                    minIdx = i;
                    minValue = lists[i]->val;
                }
            }
            // merge
            cur->next = lists[minIdx];
            cur = cur->next;
            lists[minIdx] = lists[minIdx]->next;
        }
        cur = head->next;
        delete head;
        return cur;
    }

    bool allNull(vector<ListNode *> &lists) {
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

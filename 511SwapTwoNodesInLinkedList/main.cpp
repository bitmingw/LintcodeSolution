#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // detect if v1 and v2 are present
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pos = dummy;
        ListNode* pre1 = NULL;
        ListNode* pre2 = NULL;
        while (pos->next) {
            if (pos->next->val == v1) pre1 = pos;
            if (pos->next->val == v2) pre2 = pos;
            pos = pos->next;
        }
        if (!(pre1 && pre2)) return head;
        // do the swap
        ListNode* pos1 = pre1->next;
        ListNode* pos2 = pre2->next;
        ListNode* post1 = pos1->next;
        ListNode* post2 = pos2->next;
        if (pos1 == pre2) {
            pre1->next = pos2;
            pos2->next = pos1;
            pos1->next = post2;
        } else if (pos2 == pre1) {
            pre2->next = pos1;
            pos1->next = pos2;
            pos2->next = post1;
        } else {
            pre1->next = pos2;
            pos2->next = post1;
            pre2->next = pos1;
            pos1->next = post2;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    return 0;
}

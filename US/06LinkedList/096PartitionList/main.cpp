#include <iostream>
#include <cstdint>
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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode *preHead = new ListNode(INT32_MIN);
        preHead->next = head;
        // find the place to insert smaller nodes
        ListNode *ins = preHead;
        while (ins->next && ins->next->val < x)
            ins = ins->next;
        ListNode *insPost = ins->next;
        ListNode *cur = ins->next;
        ListNode *curPost = NULL;
        while (cur) {
            if (cur->next && cur->next->val < x) {
                curPost = cur->next->next;
                ins->next = cur->next;
                cur->next->next = insPost;
                cur->next = curPost;
                ins = ins->next;
            } else {
                cur = cur->next;
            }
        }
        head = preHead->next;
        delete preHead;
        return head;
    }
};

int main() {
    Solution s;
    return 0;
}

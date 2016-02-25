#include <iostream>
using namespace std;

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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // special cases
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = new ListNode(0);  // dummy
        ListNode *cur = head;
        int localSum = 0, carry = 0;
        while (l1 && l2) {
            localSum = l1->val + l2->val + carry;
            if (localSum > 9) {
                localSum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            // add new value to linked list
            cur->next = new ListNode(localSum);
            cur = cur->next;
            // update the original
            l1 = l1->next;
            l2 = l2->next;
        }
        // deal with the case that the length are different
        ListNode *remain = NULL;
        if (l1) remain = l1;
        else if (l2) remain = l2;
        while (remain) {
            localSum = remain->val + carry;
            if (localSum > 9) {
                localSum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            // add new value to linked list
            cur->next = new ListNode(localSum);
            cur = cur->next;
            // update the original
            remain = remain->next;
        }
        // deal with the case that carry != 0
        if (carry) {
            cur->next = new ListNode(carry);
        }
        cur = head->next;
        delete head;
        return cur;
    }
};

int main() {
    Solution s;
    return 0;
}

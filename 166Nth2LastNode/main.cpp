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
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        // move fast n nodes ahead
        int cnt = 0;
        while (cnt < n && fast) {
            fast = fast->next;
            ++cnt;
        }
        // when there is less than n nodes
        if (cnt < n) return NULL;
        // move both fast & slow forward
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    Solution s;
    return 0;
}

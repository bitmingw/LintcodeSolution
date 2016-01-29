#include <vector>
#include <iostream>
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
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *start, *pre, *cur, *post;
        bool headChange = false, tailChange = false;
        start = head;
        if (m == 1) {
            headChange = true;
        } else {
            for (int i = 2; i < m; ++i) {
                start = start->next;
            }
        }
        if (headChange) {
            pre = NULL;
            cur = head;
        }
        else {
            pre = start;
            cur = pre->next;
        }
        post = cur->next;
        for (int i = 0; i <= n-m; ++i) {
            cur->next = pre;
            pre = cur;
            cur = post;
            if (post) post = post->next;
        }
        if (!headChange) {
            start->next->next = cur;
            start->next = pre;
        } else {
            start->next = cur;
            head = pre;
        }
        return head;
    }
};

int main() {
    Solution s;
    return 0;
}

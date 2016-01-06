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
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (!head) return;
        int len = listLen(head);
        if (len == 1 || len == 2) return;
        int midPoint = (len+1) / 2; // last element of first list
        // split the list to two parts
        ListNode *cur = head;
        for (int i = 1; i < midPoint; ++i) {
            cur = cur->next;
        }
        ListNode *head2 = cur->next;
        cur->next = NULL;
        head2 = reverse(head2);
        ListNode *cur1 = head, *cur2 = head2;
        ListNode *post1 = cur1->next, *post2 = cur2->next;
        while (cur1 && cur2) {
            cur2->next = post1;
            cur1->next = cur2;
            cur1 = post1;
            cur2 = post2;
            if (!post1) post1 = NULL; else post1 = post1->next;
            if (!post2) post2 = NULL; else post2 = post2->next;
        }
    }

    int listLen(ListNode *head) {
        if (!head) return 0;
        int nNode = 0;
        while (head) {
            ++nNode;
            head = head->next;
        }
        return nNode;
    }

    ListNode *reverse(ListNode *head) {
        if (!head) return NULL;
        ListNode *pre = NULL, *cur = head, *post = cur->next;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = post;
            if (!post) post = NULL; else post = post->next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    return 0;
}

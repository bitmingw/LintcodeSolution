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

struct DoubleHead {
    ListNode *head1;
    ListNode *head2;
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (!head) return NULL;
        DoubleHead dh = splitList(head);
        if (!dh.head1 && dh.head2) return dh.head2;
        if (dh.head1 && !dh.head2) return dh.head1;
        dh.head1 = sortList(dh.head1);
        dh.head2 = sortList(dh.head2);
        if (dh.head1 || dh.head2) return mergeList(dh.head1, dh.head2);
        else return NULL;
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

    DoubleHead splitList(ListNode *head) {
        DoubleHead dh;
        dh.head1 = NULL;
        dh.head2 = NULL;
        if (!head) return dh;
        int len = listLen(head);
        if (len == 1) {
            dh.head1 = head;
            return dh;
        }
        int mid = (len+1) / 2;
        ListNode *end1 = head;
        for (int i = 1; i < mid; ++i) {
            end1 = end1->next;
        }
        dh.head1 = head;
        dh.head2 = end1->next;
        end1->next = NULL;
        return dh;
    }

    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                cur->next = head1;
                head1 = head1->next;
                cur = cur->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
                cur = cur->next;
            }
        }
        if (head1) cur->next = head1;
        if (head2) cur->next = head2;
        cur = head->next;
        delete head;
        return cur;
    }
};

int main() {
    Solution s;
    return 0;
}

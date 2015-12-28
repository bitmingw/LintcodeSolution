#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

//Definition of ListNode
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2; // could be NULL
        } else if (l2 == NULL) {
            return l1;
        }
        
        ListNode *head, *head1, *head2, *ins, *cur;
        head = (l1->val <= l2->val) ? l1 : l2;
        ins = head;
        head1 = (head == l1) ? l1->next : l1;
        head2 = (head == l2) ? l2->next : l2;
        ins->next = NULL; // separate the merged list from others
        
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                cur = head1;
                head1 = head1->next;
                ins->next = cur;
                cur->next = NULL;
                ins = cur;
            } else {
                cur = head2;
                head2 = head2->next;
                ins->next = cur;
                cur->next = NULL;
                ins = cur;
            }
        }
        
        if (head1) {
            ins->next = head1;
        }
        if (head2) {
            ins->next = head2;
        }
        
        return head;
    }
};


int main() {
    return 0;
}

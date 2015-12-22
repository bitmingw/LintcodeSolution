#include <string>
#include <cstring>
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
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (head == NULL) {
            return NULL;
        } else {
            return recurRev(NULL, head);
        }
    }
    
    ListNode *recurRev(ListNode *former, ListNode *cur) {
        if (!cur->next) {
            cur->next = former;
            return cur;
        } else {
            ListNode *tail = recurRev(cur, cur->next);
            cur->next = former;
            return tail;
        }
    }
};

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;
    
    Solution s;
    cout << s.reverse(&n1)->val << endl;
    return 0;
}

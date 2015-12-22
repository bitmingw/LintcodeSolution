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
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *forward, *lag, *tmp;
        forward = head;
        lag = head;
        int count = 0;
        
        for (int i = 1; i <= n-1; ++i) {
            forward = forward->next;
        }
        while (forward->next) {
            forward = forward->next;
            count++;
        }
        for (int i = 1; i < count; ++i) {
            lag = lag->next; // go to the node before deleted node
        }
        
        if (count == 0) {
            lag = lag->next;
            delete head;
            return lag;
        } else {
            tmp = lag->next; // to be deleted
            lag->next = lag->next->next;
            delete tmp;
            return head;
        }
    }
};


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    cout << s.removeNthFromEnd(head, 1)->val << endl;
}

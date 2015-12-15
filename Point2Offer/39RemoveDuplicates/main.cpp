#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode *pre = head;
        ListNode *post = head->next;
        while (post) {
            if (pre->val != post->val) {
                pre = pre->next;
                post = post->next;
            } else {
                pre->next = post->next;
                delete post;
                post = pre->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(10);
    head->next = new ListNode(11);
    head->next->next = new ListNode(11);
    head->next->next->next = new ListNode(12);
    head = s.deleteDuplicates(head);
    cout << head->val << head->next->val << head->next->next->val << endl;
    return 0;
}

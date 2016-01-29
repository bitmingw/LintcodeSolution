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

class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        int target = INT32_MIN;
        ListNode *preHead = new ListNode(INT32_MAX);
        preHead->next = head;
        head = preHead;
        ListNode *cur = preHead, *desire = preHead;
        while (cur && cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                target = cur->next->val;
                desire = cur->next;
                while (desire) {
                    cur->next = desire->next;
                    delete desire;
                    desire = cur->next;
                    if (!desire || desire->val != target) break;
                }
            } else {
                cur = cur->next;
            }
        }
        head = head->next;
        delete preHead;
        return head;
    }
};

int main() {
    Solution s;
    return 0;
}

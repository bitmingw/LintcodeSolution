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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        while (fast && slow) {
            if (fast == slow) return true;
            if (!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

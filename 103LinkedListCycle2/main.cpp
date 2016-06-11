#include <iostream>
#include <set>

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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // detect if there is a circle
        ListNode* circle_node = has_cycle(head);
        if (!circle_node) return NULL;

        // get a set of all nodes in the circle
        set<ListNode*> all_nodes;
        while (true) {
            if (all_nodes.find(circle_node) == all_nodes.end()) {
                all_nodes.insert(circle_node);
                circle_node = circle_node->next;
            } else {
                break;
            }
        }

        // start from head and detect the start of circle
        ListNode* first_node = head;
        while (all_nodes.find(first_node) == all_nodes.end()) {
            first_node = first_node->next;
        }
        return first_node;
    }

    ListNode* has_cycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while (slow && fast) {
            if (slow == fast) return slow;
            slow = slow->next;
            if (!fast->next) return NULL;
            fast = fast->next->next;
        }
        return NULL;
    }
};

int main() {
    Solution s;
    return 0;
}

#include <iostream>
#include <cstdint>

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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return head;
        ListNode* dummy = new ListNode(INT32_MIN);
        ListNode* pre_node = dummy;
        dummy->next = head;
        while (pre_node->next) {
            ListNode* min_node = pre_node->next;
            ListNode* cur_node = min_node;
            int min_val = min_node->val;
            while (cur_node) {
                if (cur_node->val < min_val) {
                    min_node = cur_node;
                    min_val = cur_node->val;
                }
                cur_node = cur_node->next;
            }
            if (min_node == pre_node->next) {
                pre_node = min_node;
            } else {
                ListNode* pre_min_node = pre_node;
                while (pre_min_node->next != min_node) {
                    pre_min_node = pre_min_node->next;
                }
                // do update here
                pre_min_node->next = min_node->next;
                min_node->next = pre_node->next;
                pre_node->next = min_node;
                pre_node = pre_node->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};


int main() {
    Solution s;
    return 0;
}

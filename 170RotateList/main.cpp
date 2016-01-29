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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int nNode = 1;
        ListNode *cur = head;
        while (cur->next) {
            cur = cur->next;
            ++nNode;
        }
        // special cases
        if (nNode <= k) k = k % nNode;
        if (k == 0) return head;
        // normal cases
        ListNode *end = head;
        for (int i = 1; i <= nNode-k-1; ++i)
            end = end->next;
        cur->next = head;
        head = end->next;
        end->next = NULL;
        return head;
    }
};

int main() {
    Solution s;
    return 0;
}

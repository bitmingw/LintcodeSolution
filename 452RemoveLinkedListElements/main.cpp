#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        else return head;
    }
};

int main() {
    Solution s;
    return 0;
}

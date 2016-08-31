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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* post = head->next;
        ListNode* remaining = post->next;
        remaining = swapPairs(remaining);
        head->next = remaining;
        post->next = head;
        return post;
    }
};

int main() {
    Solution s;
    return 0;
}

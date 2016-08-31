#include <string>
#include <iostream>
#include <deque>

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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode* pos = head;
        int len = 0;
        while (pos != NULL) {
            pos = pos->next;
            ++len;
        }
        deque<int> q;
        pos = head;
        for (int i = 1; i <= len/2; ++i) {
            q.push_back(pos->val);
            pos = pos->next;
        }
        if (len % 2) pos = pos->next;
        for (int i = 1; i <= len/2; ++i) {
            if (q.back() == pos->val) {
                q.pop_back();
                pos = pos->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
	Solution s;
	return 0;
}

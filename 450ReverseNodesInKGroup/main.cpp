#include <iostream>
#include <vector>

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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return head;
        if (k == 1) return head;
        vector<ListNode*> starts;
        vector<ListNode*> modified;
        ListNode* pos = head;
        int cnt = k;
        while (pos) {
            if (cnt == k) {
                starts.push_back(pos);
                cnt = 0;
            }
            pos = pos->next;
            ++cnt;
        }
        split(starts);
        for (auto phead: starts) {
            if (len(phead) == k) {
                phead = reverse(NULL, phead);
                modified.push_back(phead);
            } else {
                modified.push_back(phead);
            }
        }
        assemble(modified);
        return modified[0];
    }

    void split(vector<ListNode*> starts) {
        for (int i = 0; i+1 < starts.size(); ++i) {
            ListNode* pos = starts[i];
            while (pos->next != NULL && pos->next != starts[i+1]) pos = pos->next;
            pos->next = NULL;
        }
    }

    int len(ListNode* head) {
        if (!head) return 0;
        int length = 1;
        while (head->next) {
            head = head->next;
            ++length;
        }
        return length;
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur->next == NULL) {
            cur->next = pre;
            return cur;
        } else {
            ListNode* res = reverse(cur, cur->next);
            cur->next = pre;
            return res;
        }
    }

    void assemble(vector<ListNode*> modified) {
        for (int i = 0; i+1 < modified.size(); ++i) {
            ListNode* pos = modified[i];
            while (pos->next != NULL) pos = pos->next;
            pos->next = modified[i+1];
        }
    }
};

int main() {
    Solution s;
    return 0;
}

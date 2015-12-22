#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0, stepDiff = 0;
        while (curA) {
            ++lenA;
            curA = curA->next;
        }
        while (curB) {
            ++lenB;
            curB = curB->next;
        }
        
        stepDiff = lenA - lenB;
        curA = headA;
        curB = headB;
        if (stepDiff > 0) {
            for (int i = 0; i < stepDiff; ++i) {
                curA = curA->next;
            }
        } else {
            stepDiff = 0 - stepDiff;
            for (int i = 0; i < stepDiff; ++i) {
                curB = curB->next;
            }
        }
        
        while (curA && curB) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL; // not found
    }
};

int main() {
    Solution s;
    return 0;
}

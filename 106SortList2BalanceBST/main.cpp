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
// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        int len = listLen(head);
        if (len == 1) return new TreeNode(head->val);
        int middle = len / 2;
        ListNode *leftend = head, *center = NULL, *right = NULL;
        for (int i = 0; i+1 < middle; ++i)
            leftend = leftend->next;
        center = leftend->next;
        right = center->next;
        leftend->next = NULL;
        TreeNode *root = new TreeNode(center->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(right);
        return root;
    }

    int listLen(ListNode *head) {
        if (!head) return 0;
        int nNode = 0;
        while (head) {
            ++nNode;
            head = head->next;
        }
        return nNode;
    }
};

int main() {
    Solution s;
    return 0;
}

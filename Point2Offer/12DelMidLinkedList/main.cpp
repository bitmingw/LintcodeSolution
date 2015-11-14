#include <string>
#include <cstring>
#include <vector>
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
    // copy the next element from the current linked list
    // and delete the next element
    // assume this is not the last element in the linked list
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        if (node == NULL)
            return;
        ListNode *to_del = node->next;
        node->val = to_del->val;
        node->next = to_del->next;
        delete to_del;
    }
};
 

int main() {
	return 0;
}

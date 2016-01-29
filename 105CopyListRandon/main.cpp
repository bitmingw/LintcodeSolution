#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *head2, *cur, *cur2;
        map<RandomListNode*, RandomListNode*> nodeMapping = map<RandomListNode*, RandomListNode*>();
        
        if (head == NULL) {
            return NULL;
        }
        head2 = new RandomListNode(head->label);
        nodeMapping.insert(pair<RandomListNode*, RandomListNode*>(head, head2));
        cur = head->next;
        cur2 = head2; // before the inserted node
        while (cur) {
            cur2->next = new RandomListNode(cur->label);
            cur2 = cur2->next;
            nodeMapping.insert(pair<RandomListNode*, RandomListNode*>(cur, cur2));
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            if (cur->random) {
                nodeMapping.find(cur)->second->random = nodeMapping.find(cur->random)->second;
            }
            cur = cur->next;
        }
        
        return head2;
    }
};


int main() {
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;


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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int capacity = hashTable.size() * 2;
        vector<ListNode*> reHashTable(capacity, NULL);

        vector<int> vals;
        for (auto pNode: hashTable) {
            while (pNode) {
                vals.push_back(pNode->val);
                pNode = pNode->next;
            }
        }

        for (int num: vals) {
            int pos = hashcode(num, capacity);
            ListNode* pNode = reHashTable[pos];
            if (pNode == NULL) {
                reHashTable[pos] = new ListNode(num);
            } else {
                while (pNode->next) {
                    pNode = pNode->next;
                }
                pNode->next = new ListNode(num);
            }
        }

        return reHashTable;
    }

    int hashcode(int key, int capacity) {
        return (key % capacity + capacity) % capacity;
    }
};

int main() {
    Solution s;
    return 0;
}

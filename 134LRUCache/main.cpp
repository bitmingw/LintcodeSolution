#include <iostream>
#include <unordered_map>

using namespace std;

class DLinkedList {
public:
    int val;
    DLinkedList* previous;
    DLinkedList* next;
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        this->capacity = 0;
        this->max_capacity = capacity;
        head = new DLinkedList();
        tail = new DLinkedList();
        head->next = tail;
        tail->previous = head;
    }
    
    // @return an integer
    int get(int key) {
        if (table.find(key) == table.end()) return -1;
        else {
            DLinkedList* cur = table[key];
            DLinkedList* cpre = cur->previous;
            DLinkedList* cpost = cur->next;
            DLinkedList* hpost = head->next;
            if (cpre != head) {
                head->next = cur;
                cur->previous = head;
                cur->next = hpost;
                hpost->previous = cur;
                cpre->next = cpost;
                cpost->previous = cpre;
            }
            return cur->val;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (max_capacity == 0) return;
        if (table.find(key) != table.end()) {
            DLinkedList* cur = table[key];
            cur->val = value;
            DLinkedList* cpre = cur->previous;
            DLinkedList* cpost = cur->next;
            DLinkedList* hpost = head->next;
            if (cpre != head) {
                head->next = cur;
                cur->previous = head;
                cur->next = hpost;
                hpost->previous = cur;
                cpre->next = cpost;
                cpost->previous = cpre;
            }
        } else {
            if (capacity < max_capacity) {
                DLinkedList* inserted = new DLinkedList();
                inserted->val = value;
                ++capacity;
                table[key] = inserted;
                DLinkedList* hpost = head->next;
                head->next = inserted;
                inserted->previous = head;
                inserted->next = hpost;
                hpost->previous = inserted;
            } else {
                DLinkedList* addr = tail->previous;
                for (auto elem: table) {
                    if (elem.second == addr) {
                        table.erase(elem.first);
                        break;
                    }
                }
                table[key] = addr;
                addr->val = value;
                DLinkedList* cpre = addr->previous;
                DLinkedList* hpost = head->next;
                if (cpre != head) {
                    head->next = addr;
                    addr->previous = head;
                    addr->next = hpost;
                    hpost->previous = addr;
                    cpre->next = tail;
                    tail->previous = cpre;
                }
            }
        }
    }
private:
    int capacity;
    int max_capacity;
    DLinkedList* head;
    DLinkedList* tail;
    unordered_map<int, DLinkedList*> table;
};

int main() {
    return 0;
}

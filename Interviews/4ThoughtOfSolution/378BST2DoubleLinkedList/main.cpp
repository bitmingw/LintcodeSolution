#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        DoublyListNode *linkRoot = new DoublyListNode(root->val);
        DoublyListNode *linkLeft = goTail(convert(root->left));
        DoublyListNode *linkRight = goHead(convert(root->right));
        return goHead(bind(linkLeft, linkRoot, linkRight));
    }
    
    // return the pointer to the linkRoot
    DoublyListNode* convert(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        DoublyListNode *linkRoot = new DoublyListNode(root->val);
        DoublyListNode *linkLeft = goTail(convert(root->left));
        DoublyListNode *linkRight = goHead(convert(root->right));
        return bind(linkLeft, linkRoot, linkRight);
    }
    
    DoublyListNode* goHead(DoublyListNode *node) {
        if (node == NULL) {
            return NULL;
        }
        while (node->prev) {
            node = node->prev;
        }
        return node;
    }
    
    DoublyListNode* goTail(DoublyListNode *node) {
        if (node == NULL) {
            return NULL;
        }
        while (node->next) {
            node = node->next;
        }
        return node;
    }
    
    DoublyListNode* bind(DoublyListNode *prev, DoublyListNode *node, DoublyListNode *next) {
        if (prev) {
            prev->next = node;
        }
        if (next) {
            next->prev = node;
        }
        node->prev = prev;
        node->next = next;
        return node;
    }
};


int main() {
    return 0;
}

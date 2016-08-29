#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        c = 0;
        terminate = false;
        for (int i = 1; i <= 26; ++i) {
            sub[i-1] = NULL;
        }
    }
    char c;
    bool terminate;
    TrieNode* sub[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* pos = root;
        int n = word.length();
        if (n == 0) return;
        for (int i = 0; i < n; ++i) {
            char next = word[i];
            if (pos->sub[next - 'a']) {
                pos = pos->sub[next - 'a'];
            } else {
                pos->sub[next - 'a'] = new TrieNode();
                pos->sub[next - 'a']->c = next;
                pos = pos->sub[next - 'a'];
            }
        }
        pos->terminate = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* pos = root;
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            char next = word[i];
            if (pos->sub[next - 'a'])
                pos = pos->sub[next - 'a'];
            else
                return false;
        }
        if (pos->terminate) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* pos = root;
        int n = prefix.length();
        for (int i = 0; i < n; ++i) {
            char next = prefix[i];
            if (pos->sub[next - 'a'])
                pos = pos->sub[next - 'a'];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    return 0;
}

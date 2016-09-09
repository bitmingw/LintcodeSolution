#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode() {}
    TrieNode* sub[26];
    char c;
    bool end;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* pos = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (pos->sub[c - 'a']) {
                pos = pos->sub[c - 'a'];
            } else {
                pos->sub[c - 'a'] = new TrieNode();
                pos = pos->sub[c - 'a'];
                pos->c = c;
                pos->end = false;
            }
        }
        pos->end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, TrieNode* pos) {
        if (!pos) return false;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (c == '.') {
                vector<char> possibles;
                for (char pc = 'a'; pc <= 'z'; ++pc) {
                    if (pos->sub[pc - 'a']) possibles.push_back(pc);
                }
                for (char pc: possibles) {
                    string new_str(word.begin()+i, word.end());
                    new_str[0] = pc;
                    if (search(new_str, pos)) return true;
                }
                return false;
            } else {
                if (pos->sub[c - 'a']) {
                    pos = pos->sub[c - 'a'];
                } else {
                    return false;
                }
            }
        }
        return pos->end == true;
    }

private:
    TrieNode* root;
};

// [addWord("ran"), addWord("rune"), addWord("runner"), addWord("runs"), addWord("add"), addWord("adds"), addWord("adder"), addWord("addee"), search("r.n"), search("ru.n.e"), search("add"), search("add."), search("adde."), search(".an."), search("...s"), search("....e."), search("......."), search("..n.r")]

int main() {
    WordDictionary dict;
    dict.addWord("ran");
    dict.addWord("rune");
    dict.addWord("runner");
    dict.addWord("runs");
    dict.addWord("add");
    dict.addWord("adds");
    dict.addWord("adder");
    dict.addWord("addee");
    cout << dict.search("r.n") << endl;
    cout << dict.search("ru.n.e") << endl;
    cout << dict.search("add") << endl;
    cout << dict.search("add.") << endl;
    cout << dict.search("adde.") << endl;
    cout << dict.search(".an.") << endl;
    cout << dict.search("...s") << endl;
    cout << dict.search("....e.") << endl;
    cout << dict.search(".......") << endl;
    cout << dict.search("..n.r") << endl;
    return 0;
}

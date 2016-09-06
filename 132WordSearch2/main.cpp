#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    char c;
    TrieNode* next[26];
    bool end;
};

class TrieTree {
public:
    TrieNode* root;
    TrieTree() {
        root = new TrieNode();
    }
    void put(string& word) {
        if (word.empty()) root->end = true;
        else {
            TrieNode* pos = root;
            for (int i = 0; i < word.size(); ++i) {
                char cc = word[i];
                if (pos->next[cc - 'a']) {
                    pos = pos->next[cc - 'a'];
                } else {
                    pos->next[cc - 'a'] = new TrieNode();
                    pos = pos->next[cc - 'a'];
                    pos->c = cc;
                }
            }
            pos->end = true;
        }
    }
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        vector<string> res;
        if (board.empty() || board[0].empty()) {
            for (auto w: words) {
                if (w.empty()) {
                    res.push_back("");
                    break;
                }
            }
            return res;
        }
        // construct a trie for words
        TrieTree trie;
        for (string str: words) {
            trie.put(str);
        }
        // do the DFS search
        set<int> visited;
        vector<char> str;
        vector<TrieNode*> pos;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited.clear();
                str.clear();
                pos.clear();
                pos.push_back(trie.root);
                wordSearchII(res, board, pos, str, visited, i, j);
            }
        }
        // remove duplicates
        set<string> sres(res.begin(), res.end());
        res.clear();
        res = vector<string>(sres.begin(), sres.end());
        return res;
    }

    void wordSearchII(vector<string>& res, vector<vector<char>>& board, vector<TrieNode*>& pos, \
        vector<char>& str, set<int>& visited, int i, int j) {
        // detect if it is a valid position
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        if (visited.find(i*n+j) != visited.end()) return;
        // look at the trie
        char cc = board[i][j];
        TrieNode* cur = pos.back();
        if (!cur->next[cc - 'a']) return;
        else {
            cur = cur->next[cc - 'a'];
            pos.push_back(cur);
            str.push_back(cc);
            visited.insert(i*n+j);
            // find the result
            if (cur->end) {
                string assemble = "";
                for (char ccc: str) {
                    assemble += string(1, ccc);
                }
                res.push_back(assemble);
            }
            // do DFS
            wordSearchII(res, board, pos, str, visited, i-1, j);
            wordSearchII(res, board, pos, str, visited, i+1, j);
            wordSearchII(res, board, pos, str, visited, i, j-1);
            wordSearchII(res, board, pos, str, visited, i, j+1);
            visited.erase(i*n+j);
            str.pop_back();
            pos.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'d', 'o', 'a', 'f'},
                                  {'a', 'g', 'a', 'i'},
                                  {'d', 'c', 'a', 'n'}};
    vector<string> words = {"dog", "dad", "dgdg", "can", "again"};
    cout << s.wordSearchII(board, words).size() << endl;
    return 0;
}

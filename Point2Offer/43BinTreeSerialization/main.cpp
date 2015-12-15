#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string data = "";
        if (!root) {
            data += "#";
            return data;
        }
        data += to_string(root->val);
        data += ",";
        data += serialize(root->left);
        data += ",";
        data += serialize(root->right);
        return data;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    
    TreeNode *deserialize(string data) {
        // change the string to vector
        vector<string> sVec = split(data, ',');
        /*
        for (vector<string>::iterator it = sVec.begin(); it != sVec.end(); ++it) {
            cout << *it << " ";
        }
        */
        // build up
        if (sVec[0] == "#") return NULL;
        int idx = 0;
        TreeNode *root = new TreeNode(stoi(sVec[idx]));
        root->left = deserializeSub(sVec, ++idx);
        root->right = deserializeSub(sVec, ++idx);
        return root;
    }
    
    vector<string> split(string &data, char delim) {
        vector<string> frags;
        stringstream ss(data);
        string item;
        while (getline(ss, item, delim)) {
            frags.push_back(item);
        }
        return frags;
    }
    
    TreeNode *deserializeSub(vector<string> &vec, int &idx) {
        if (idx >= vec.size() || vec[idx] == "#") return NULL;
        else {
            TreeNode *node = new TreeNode(stoi(vec[idx]));
            node->left = deserializeSub(vec, ++idx);
            node->right = deserializeSub(vec, ++idx);
            return node;
        }
    }
    
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    string data = s.serialize(root);
    TreeNode * newRoot = s.deserialize(data);
    cout << newRoot->val << " " << newRoot->left->val << " " << newRoot->right->val
    << " " << newRoot->right->left->val << " " << newRoot->right->right->val << endl;
    return 0;
}

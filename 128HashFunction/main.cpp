#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        long hash = 0;
        for (int i = 0; i < key.size(); ++i) {
            hash *= 33;
            hash += key[i];
            hash %= HASH_SIZE;
        }
        return static_cast<int>(hash);
    }
};

int main() {
    Solution s;
    return 0;
}

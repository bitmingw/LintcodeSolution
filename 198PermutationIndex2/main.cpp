#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        if (A.size() == 1) return 1;
        map<int, int> table;
        for (int elem: A) {
            if (table.find(elem) == table.end()) {
                table[elem] = 1;
            } else {
                table[elem] += 1;
            }
        }
        set<int> appeared;
        long long index = 0;
        for (int i = 0; i < A.size(); ++i) {
            appeared.clear();
            for (int j = i+1; j < A.size(); ++j) {
                if (A[j] < A[i] && appeared.find(A[j]) == appeared.end()) {
                    appeared.insert(A[j]);
                    table[A[j]] -= 1;
                    index += permutation(table);
                    table[A[j]] += 1;
                }
            }
            table[A[i]] -= 1;
        }
        return index + 1;
    }

    long long factorial(int n) {
        if (n == 0) return 1;
        long long res = 1;
        for (int i = 2; i <= n; ++i) {
            res *= i;
        }
        return res;
    }

    long long permutation(map<int, int>& table) {
        long long den = 1;
        int sum = 0;
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (it->second == 0) continue;
            else {
                den *= factorial(it->second);
                sum += it->second;
            }
        }
        return factorial(sum) / den;
    }
};

int main() {
    Solution s;
    return 0;
}

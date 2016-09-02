#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int cnt = 1;
        sort(primes.begin(), primes.end());
        priority_queue<long long, vector<long long>, greater<long long>> storage;
        set<long long> visited;
        for (int elem: primes) {
            storage.push(elem);
        }
        while (storage.size()) {
            long long val = storage.top();
            storage.pop();
            if (visited.find(val) != visited.end()) continue;
            visited.insert(val);
            ++cnt;
            if (cnt == n) return (int)val;
            for (int elem: primes) {
                storage.push(val * elem);
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}

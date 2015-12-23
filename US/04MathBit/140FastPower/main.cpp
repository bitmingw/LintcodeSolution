#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
     // modular property: (a mod n) (b mod n) mod n = (ab) mod n
    int fastPower(int a, int b, int n) {
        if (b == 1) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return a % b;
        }
        if (n % 2 == 0) {
            long long base = fastPower(a, b, n/2) % b;
            return ((base * base) % b) % b;
        } else {
            long long base = fastPower(a, b, n/2) % b;
            return ((base * base % b) * (a % b)) % b;
        }
    }
};


int main() {
    Solution s;
    cout << "2^31 mod 3 = " << s.fastPower(2, 3, 31) << endl; // 2
    cout << "100^1000 mod 1000 = " << s.fastPower(100, 1000, 1000) << endl; // 0
    cout << "1^2147483647 mod 2147483647 = " << s.fastPower(1, 2147483647, 2147483647) << endl; // 1
    cout << "109^1000001 mod 10000007 = " << s.fastPower(109, 10000007, 1000001) << endl; // 5249911
    cout << "2147483647^2147483647 mod 1147483647 = " << s.fastPower(2147483647, 1147483647, 2147483647) << endl; // 444545335
    return 0;
}

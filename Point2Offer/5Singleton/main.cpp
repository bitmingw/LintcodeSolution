#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        static Solution instance;
        return &instance;
    }

private:
    Solution() {}
};

int main() {
    
    Solution *s = Solution::getInstance();
    Solution *t = Solution::getInstance();
    cout << s << endl;
    cout << t << endl;
    cout << (static_cast<void*>(s) == static_cast<void*>(t)) << endl;
    return 0;
}

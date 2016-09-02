#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        int len = originalStr.size();
        if (size > len) {
            string left(size-len, padChar);
            return left + originalStr;
        } else {
            return originalStr;
        }
    }
};

int main() {
    return 0;
}

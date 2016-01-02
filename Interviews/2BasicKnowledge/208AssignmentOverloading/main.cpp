#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (!object.m_pData) {
            this->m_pData = NULL;
            return Solution();
        }
        int len = strlen(object.m_pData);
        char *p = new char[len+1];
        strcpy(p, object.m_pData);
        this->m_pData = p;
        return Solution(p);
    }
};

int main() {
    char data[6] = "Hello";
    Solution A(data);
    Solution B, C;
    B = A;
    C = B = A;
    printf("%s\n", A.m_pData);
    printf("%s\n", B.m_pData);
    printf("%s\n", C.m_pData);
    return 0;
}

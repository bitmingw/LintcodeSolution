#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        if (!A.size()) return 0;
        int vec_len = A.size();
        for (int i = 0; i < vec_len; ++i) {
            if (A[i] == elem) {
                A.erase(A.begin()+i);
                --i;
                --vec_len;
            }
        }
        return A.size();
    }
};

int main() {
    Solution s;
    int arr[] = {0, 4, 4, 0, 0, 2, 4, 4};
    vector<int> vec(arr, arr+8);
    cout << s.removeElement(vec, 4) << endl;  // should be 4
    return 0;
}

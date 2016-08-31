#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        if (A.empty() || B.empty() || (A.size() != B.size()))
            return 2.0;
        double num = 0;
        double moda = 0, modb = 0;
        for (int i = 0; i < A.size(); ++i) {
            num += A[i] * B[i];
            moda += A[i] * A[i];
            modb += B[i] * B[i];
        }
        moda = sqrt(moda);
        modb = sqrt(modb);
        if (moda == 0.0 || modb == 0.0) return 2.0;
        return num / (moda * modb);
    }
};

int main() {
    Solution s;
    return 0;
}

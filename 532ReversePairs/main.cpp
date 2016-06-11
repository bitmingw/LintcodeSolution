#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long total = 0;
        vector<int> aux(A);
        cout << "Allocate the memory" << endl;
        mergesort(A, aux, 0, A.size(), total);
        return total;
    }

    void mergesort(vector<int>& A, vector<int>& aux, 
            int lo, int hi, long long & total) {
        if (lo + 1 >= hi) return;
        int mi = lo + (hi - lo) / 2;
        mergesort(A, aux, lo, mi, total);
        mergesort(A, aux, mi, hi, total);
        merge(A, aux, lo, mi, hi, total);
    }

    void merge(vector<int>& A, vector<int>& aux,
            int lo, int mi, int hi, long long & total) {
        // merge A[lo:mi] and A[mi:hi] to aux[lo:hi]
        int i = lo;
        int j = mi;
        int k = lo;
        while (i < mi && j < hi) {
            if (A[i] <= A[j]) {
                aux[k++] = A[i++];
            } else {
                aux[k++] = A[j++];
                total += (mi - i);
            }
        }
        while (i < mi) {
            aux[k++] = A[i++];
        }
        while (j < hi) {
            aux[k++] = A[j++];
        }
        // copy aux[lo:hi] back to A[lo:hi]
        k = lo;
        while (k < hi) {
            A[k] = aux[k];
            ++k;
        }
    }
};

int main() {
    Solution s;
    int data[] = {2, 4, 1, 3, 5};
    vector<int> data_vec = vector<int>(data, data+5);
    cout << s.reversePairs(data_vec) << endl;  // should be 3
    return 0;
}

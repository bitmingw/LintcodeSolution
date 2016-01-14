#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> subset;
        allSets.push_back(subset);
        if (S.empty()) return allSets;
        vector<int> sortedS(S);
        sort(sortedS.begin(), sortedS.end());
        for (int i = 1; i <= sortedS.size(); ++i) {
            subset.clear();
            combination(sortedS, allSets, subset, i, 0);
        }
        return allSets;
    }

    void combination(vector<int> &array, vector<vector<int>> &allSets, vector<int> &set, int i, int idx) {
        if (set.size() == i) {
            if (!equal(allSets, set))
                allSets.push_back(set);
            return;
        }
        for (int j = idx; j < array.size(); ++j) {
            set.push_back(array[j]);
            combination(array, allSets, set, i, j+1);
            set.pop_back();
        }
    }

    bool equal(vector<int> &a, vector<int> &b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool equal(vector<vector<int>> &set, vector<int> &b) {
        for (int i = 0; i < set.size(); ++i) {
            if (equal(set[i], b)) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    int S[] = {1, 2};
    vector<int> SS(S, S+2);
    vector<vector<int>> sets = s.subsetsWithDup(SS);
    for (int i = 0; i < sets.size(); ++i) {
        for (int j = 0; j < sets[i].size(); ++j) {
            cout << sets[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

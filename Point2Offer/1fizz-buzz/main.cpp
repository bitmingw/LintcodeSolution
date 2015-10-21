#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else {
                results.push_back(std::to_string(i));
            }
        }
        return results;
    }
};

int main() {
	Solution s = Solution();
	vector<string> results = s.fizzBuzz(15);
	for (vector<string>::iterator it = results.begin(); it != results.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";
	return 0;
}

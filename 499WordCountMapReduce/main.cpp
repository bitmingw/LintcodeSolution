#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 */

class WordCountMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        while (!input->done()) {
            string val = input->value();
            while (val.size()) {
                int blank_pos = val.find(' ');
                if (blank_pos != string::npos) {
                    string word(val.begin(), val.begin()+blank_pos);
                    val = string(val.begin()+blank_pos+1, val.end());
                    output(word, 1);
                } else {
                    output(val, 1);
                    break;
                }
            }
            input->next();
        }
    }
};


class WordCountReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        int cnt = 0;
        while (!input->done()) {
            int val = input->value();
            cnt += val;
            input->next();
        }
        output(key, cnt);
    }
};

int main() {
    return 0;
}

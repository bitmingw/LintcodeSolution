#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class MinStack {
private:
    vector<int> stack;
    vector<int> mstack;
    
public:
    MinStack() {
        stack = vector<int>();
        mstack = vector<int>();
    }

    void push(int number) {
        stack.push_back(number);
        if (mstack.size() == 0 || number <= mstack.back()) {
            mstack.push_back(number);
        }
    }

    int pop() {
        int num = stack.back();
        stack.pop_back();
        if (mstack.size() && num == mstack.back()) {
            mstack.pop_back();
        }
        return num;
    }

    int min() {
        return mstack.back();
    }
};



int main() {
    return 0;
}

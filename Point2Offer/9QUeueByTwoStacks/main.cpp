#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
        stack1 = stack<int>();
        stack2 = stack<int>();
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        int val;
        if (!stack2.empty()) {
             val = stack2.top();
             stack2.pop();
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            val = stack2.top();
            stack2.pop();
        }
        return val;
    }

    int top() {
        // write your code here
        if (!stack2.empty()) {
            return stack2.top();
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            return stack2.top();
        }
    }
};
 

int main() {
	Queue q = Queue();
    q.push(1);
    cout << q.pop() << endl;
    q.push(2);
    q.push(3);
    cout << q.top() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
	return 0;
}

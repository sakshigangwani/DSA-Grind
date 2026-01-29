#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if(st.empty()) return;
        if(st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(minSt.empty()) return -1;
        return minSt.top();
    }
};

int main() {
    MinStack* obj = new MinStack();

    vector<int> inputs = {3, 5, 2, 1, 1, -1};
    for(int val : inputs) {
        if(val != -1) {
            obj->push(val);
        }
    }

    cout << obj->getMin() << endl;
    cout << obj->top() << endl;

    obj->pop();
    obj->pop();
    obj->pop();

    cout << obj->getMin() << endl;
    cout << obj->top() << endl;

    delete obj;
    return 0;
}
// Time Complexity: O(1) for push, pop, top, and getMin operations.
// Space Complexity: O(n) where n is the number of elements in the stack.
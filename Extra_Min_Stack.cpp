#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainSt;
    stack<int> minSt;

public:
    MinStack() {}
    
    void push(int val) {
        mainSt.push(val);
        if (minSt.empty() || val <= minSt.top()) {
          minSt.push(val);
        }
    }
    
    void pop() {
        if (mainSt.top() == minSt.top()) {
          minSt.pop();
        }
        mainSt.pop();
    }
    
    int top() {
        return mainSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() 
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    delete obj;
    
    return 0;
}
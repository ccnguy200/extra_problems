#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> inSt, outSt;

public:
  MyQueue() {}
    
  void push(int x) {
    inSt.push(x);
  }
    
  int pop() {
    if (outSt.empty()) {
      while (!inSt.empty()) {
        outSt.push(inSt.top());
        inSt.pop();
      }
    }
    int val = outSt.top();
    outSt.pop();
    return val;
  }
    
  int peek() {
    if (outSt.empty()) {
      while (!inSt.empty()) {
        outSt.push(inSt.top());
        inSt.pop();
      }
    }
    return outSt.top();
  }
    
  bool empty() {
    return inSt.empty() && outSt.empty();
  }
};

int main() 
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << (obj->empty() ? "true" : "false") << endl;
    
    return 0;
}
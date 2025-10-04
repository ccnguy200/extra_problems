#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    int q;
    cout <<"Please enter the number of queries: " << endl;
    cin >> q;
    
    stack<int> st1, st2;
    
    while (q--) {
      int type;
      cout << "Please choose type:" << endl;
      cout << "1-Enqueue" << endl;
      cout << "2-Dequeue" << endl;
      cout << "3-Print front element" << endl;
      cin >> type;
      
      if (type == 1) {
        int num;
        cout << "Please enter number to enqueue: " << endl;
        cin >> num;
        st1.push(num);
      }
      else if (type == 2) {
        if (st2.empty()) {
          while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
          }
        }
        if (!st2.empty()) {
          st2.pop();
        }
      }
      else if (type == 3) {
        if (st2.empty()) {
          while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
          }
        }
        if (!st2.empty()) {
          cout << st2.top() << endl;
        }
      }
      else {
        cout << "Invalid type!" << endl;
      }
    }
    
    return 0;
}
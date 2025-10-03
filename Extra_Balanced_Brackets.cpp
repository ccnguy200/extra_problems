#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
  stack<char> st;
  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') { st.push(c); }
    else {
      if (st.empty()) return "NO";
      char top = st.top();
      st.pop();
      if ((c == ')' && top != '(') || 
          (c == '}' && top != '{') ||
          (c == ']' && top != '[')) {
          return "NO";
      }
    }
  }
  return st.empty() ? "YES" : "NO";
}

int main() 
{
    int n;
    cout << "Please enter number of strings: " << endl;
    cin >> n;
    
    while (n--) {
      string s;
      cout << "Please enter a string: " << endl;
      cin >> s;
      cout << isBalanced(s) << endl;
    }
    
    return 0;
}
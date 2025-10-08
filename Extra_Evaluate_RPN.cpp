#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
      string token = tokens[i];
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        int result = 0;
        if (token == "+") { result = second+first; }
        else if (token == "-") { result = second-first; }
        else if (token == "*") { result = second*first; }
        else if (token == "/") { result = second/first; }
        st.push(result);
      }
      else { st.push(stoi(token)); }
    }
    return st.top();
  }
};

int main() 
{
    Solution sol;
    
    vector<string> tokens1 = {"2","1","+","3","*"};
    cout << "Output 1: " << sol.evalRPN(tokens1) << endl;
    
    vector<string> tokens2 = {"4","13","5","/","+"};
    cout << "Output 2: " << sol.evalRPN(tokens2) << endl;
    
    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Output 3: " << sol.evalRPN(tokens3) << endl;
    
    return 0;
}
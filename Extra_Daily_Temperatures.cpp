#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    vector<int> answer(size,0);
    stack<int> st;
    
    for (int i = 0; i < size; i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int prevD = st.top();
        st.pop();
        answer[prevD] = i-prevD;
      }
      st.push(i);
    }
    return answer;
  }
};

int main() 
{
    Solution sol;
    int size;
    cout <<"Please enter number of temperatures: " << endl;
    cin >> size;
    
    vector<int> temperatures(size);
    cout << "Please enter " << size << " temperatures: " << endl;
    for (int i = 0; i < size; i++) {
      cin >> temperatures[i];
    }
    
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
      cout << result[i];
      if (i != result.size()-1) { cout << ","; }
    }
    cout << "]" << endl;
    
    return 0;
}
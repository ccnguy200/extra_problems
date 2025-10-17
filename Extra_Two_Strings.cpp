#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void twoStrings(string s1, string s2) {
  unordered_set<char> chars;
  for (char c : s1) {
    chars.insert(c);
  }
  for (char c : s2) {
    if (chars.count(c) > 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
  return;
}

int main() 
{
    int p;
    cout << "Please enter number of test cases: " << endl;
    cin >> p;
    
    while (p--) {
      string s1, s2;
      cout << "Please enter two words: " << endl;
      cin >> s1 >> s2;
      twoStrings(s1, s2);
    }
    
    return 0;
}
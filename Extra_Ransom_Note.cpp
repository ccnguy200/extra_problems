#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void checkMagazine (vector<string> magazine, vector<string> note) {
  unordered_map<string, int> wordCount;
  
  for (int i = 0; i < magazine.size(); i++) {
    wordCount[magazine[i]]++;
  }
  
  for (int i = 0; i < note.size(); i++) {
    if (wordCount[note[i]] == 0) {
      cout << "No" << endl;
      return;
    }
    wordCount[note[i]]--;
  }
  
  cout << "Yes" << endl;
}

int main() 
{
    int m, n;
    cout << "Please enter number of words for magazine and note: " << endl;
    cin >> m >> n;
    
    vector<string> magazine(m);
    vector<string> note(n);
    
    for (int i = 0; i < m; i++) {
      cout << "Please enter word from magazine: " << endl;
      cin >> magazine[i];
    }
    
    for (int i = 0; i < n; i++) {
      cout << "Please enter word from note: " << endl;
      cin >> note[i];
    }
    
    checkMagazine(magazine, note);
    
    return 0;
}
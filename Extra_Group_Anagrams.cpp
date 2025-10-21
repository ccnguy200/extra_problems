#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (int i = 0; i < strs.size(); i++) {
        string key = strs[i];
        sort(key.begin(), key.end());
        groups[key].push_back(strs[i]);
    }
    vector<vector<string>> result;
    unordered_map<string, vector<string>>::iterator groupIt;
    for (groupIt = groups.begin(); groupIt != groups.end(); ++groupIt) {
        result.push_back(groupIt->second);
    }
    return result;
}

int main() {
  int numWords;
  cout << "Please enter number of words: " << endl;
  cin >> numWords;
  
  vector<string> words;
  while (numWords != 0) {
    string word;
    cout << "Please enter a word: " << endl;
    cin >> word;
    words.push_back(word);
    numWords--;
  }
  
  vector<vector<string>> result = groupAnagrams(words);
  for (int i = 0; i < result.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < result[i].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << "]" << endl;
  }

  return 0;
  
}
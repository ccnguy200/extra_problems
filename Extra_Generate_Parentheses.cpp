#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recAdd(vector<string>& result, string curr, int open, int close, int n) {
    if (curr.size() == 2 * n) {
        result.push_back(curr);
        return;
    }
    if (open < n)
        recAdd(result, curr + "(", open + 1, close, n);
    if (close < open)
        recAdd(result, curr + ")", open, close + 1, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    recAdd(result, "", 0, 0, n);
    return result;
}

int main() {
    int n;
    cout << "Please enter number of pairs: " << endl;
    cin >> n;
    
    vector<string> final = generateParenthesis(n);
    for (int i = 0; i < final.size(); i++) {
        cout << final[i] << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxProfit = 0;
        
        for (int i = 0; i < size; i++) {
          for (int j = i+1; j < size; j++) {
            int currProfit = prices[j] - prices[i];
            if (currProfit > maxProfit) {
              maxProfit = currProfit;
            }
          }
        }
        return maxProfit;
    }
};

int main() 
{
    Solution s;
    vector<int> prices;
    int num;
    
    cout << "Please enter the prices each day: " << endl;
    while (cin >> num) {
      prices.push_back(num);
      if (cin.peek() == '\n') {
        break;
      }
    }
    
    cout << "Max profit: " << s.maxProfit(prices) << endl;
    
    return 0;
}
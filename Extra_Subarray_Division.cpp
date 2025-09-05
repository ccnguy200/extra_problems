#include <iostream>
#include <vector>
using namespace std;

int Birthday (vector<int>& nums, int d, int m) {
  int size = nums.size();
  int numWays = 0;
  
  for (int i = 0; i <= size-m; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += nums[i+j];
    }
    if (sum == d) {
      numWays++;
    }
  }
  
  return numWays;
}

int main() 
{
    int size, day, month;
    cin >> size;
    
    vector <int> nums(size);
    for (int i = 0; i < size; i++) {
      cin >> nums[i];
    }
    
    cin >> day >> month;
    
    cout << Birthday (nums, day, month);
    
    return 0;
}
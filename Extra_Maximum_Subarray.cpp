#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = 0;
        
    for (int i = 0; i < nums.size(); i++) {
      currSum += nums[i];
      if (currSum > maxSum) {
        maxSum = currSum;
      }
      if (currSum < 0) {
        currSum = 0;
      }
    }
        
    return maxSum;
  }
};

int main() 
{
  Solution sol;
  
  int size;
  cin >> size;
  vector<int> nums(size);
  
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }
  
  cout << "Largest sum is " << sol.maxSubArray(nums) << endl;
    
  return 0;
}
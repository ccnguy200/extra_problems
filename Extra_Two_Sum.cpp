#include <iostream>
#include <vector>
using namespace std;

void twoSum (int nums[], int size, int target) {
  for (int i = 0; i < size; i++) {
    for (int j = i+1; j < size; j++) {
      if (nums[i] + nums[j] == target) {
        cout << "[" << i << ", " << j << "]" << endl;
        return;
      }
    }
  }
}

int main() 
{
    vector<int> userNums;
    int num, targetSum;
    
    cout << "Please enter your numbers: " << endl;
    while (cin >> num) {
      userNums.push_back(num);
      if (cin.peek() == '\n') {
        break;
      }
    }
    
    cout << "Please enter your target sum: " << endl;
    cin >> targetSum;
    
    int size = userNums.size();
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = userNums[i];
    }
    
    twoSum (arr, size, targetSum);
    
    return 0;
}
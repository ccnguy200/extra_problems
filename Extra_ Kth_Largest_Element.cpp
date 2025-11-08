#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i <= nums.size(); i++) {
        minHeap.push(i);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main() {
    int n, k;
    cout << "Please the number of elements: " << endl;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Please enter the kth number: " << endl;
    cin >> k;
    
    if (k < 4) {
      if (k==1) { cout << "The " << k << "st largest element is " << findKthLargest(nums, k) << endl; }
      else if (k==2) { cout << "The " << k << "nd largest element is " << findKthLargest(nums, k) << endl; }
      else { cout << "The " << k << "rd largest element is " << findKthLargest(nums, k) << endl; }
    }
    else { cout << "The " << k << "th largest element is " << findKthLargest(nums, k) << endl; }

    return 0;
}

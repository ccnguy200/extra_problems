#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> tracker(n, 1);
        
        int preIndex = 1;
        for (int i = 0; i < n; i++) {
            tracker[i] = preIndex;
            preIndex *= nums[i];
        }
        int postIndex = 1;
        for (int i = n - 1; i >= 0; i--) {
            tracker[i] *= postIndex;
            postIndex *= nums[i];
        }
        
        return tracker;
    }
};

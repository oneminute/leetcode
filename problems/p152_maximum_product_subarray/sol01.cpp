/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int safeMultiply(int a, int b) {
        if (a == 0 || b == 0) return 0;
        if (a > 0 && b > 0 && a > INT_MAX / b) return INT_MAX;
        if (a > 0 && b < 0 && b < INT_MIN / a) return INT_MIN;
        if (a < 0 && b > 0 && a < INT_MIN / b) return INT_MIN;
        if (a < 0 && b < 0 && a < INT_MAX / b) return INT_MAX;
        return a * b;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        
        for (int i = 1; i < n; i++) {
            int nextMax = max({nums[i], 
                               safeMultiply(currMax, nums[i]), 
                               safeMultiply(currMin, nums[i])});
            int nextMin = min({nums[i], 
                               safeMultiply(currMax, nums[i]), 
                               safeMultiply(currMin, nums[i])});
            
            currMax = nextMax;
            currMin = nextMin;
            maxProd = max(maxProd, currMax);
        }
        
        return maxProd;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {2,3,-2,4};
        int result = s.maxProduct(nums);
        cout << result << endl;
    }
    {
        vector<int> nums = {0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0};
        int result = s.maxProduct(nums);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}
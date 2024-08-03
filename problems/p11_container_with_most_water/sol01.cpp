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
    int maxArea(vector<int>& height) {
        int maxAmount = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int amount = min(height[left], height[right]) * (right - left);
            if (amount > maxAmount)
                maxAmount = amount;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxAmount;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,8,6,2,5,4,8,3,7};
        int result = s.maxArea(nums);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}
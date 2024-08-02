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
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int minValue = nums[0];
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= nums[l]) {
                if (nums[l] < minValue)
                    minValue = nums[l];
                l = m + 1;
            }
            if (nums[m] <= nums[r]) {
                if (nums[m] < minValue)
                    minValue = nums[m];
                r = m - 1;
            }
        }
        return minValue;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {3,4,5,1,2};
        int result = s.findMin(nums);
        cout << result << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int result = s.findMin(nums);
        cout << result << endl;
    }
    {
        vector<int> nums = {11,13,15,17};
        int result = s.findMin(nums);
        cout << result << endl;
    }
    {
        vector<int> nums = {2,1};
        int result = s.findMin(nums);
        cout << result << endl;
    }
    {
        vector<int> nums = {3,1,2};
        int result = s.findMin(nums);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}
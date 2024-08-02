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
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            // cout << l << ", " << m << ", " << r << endl;
            if (nums[m] == target)
                return m;
            
            if (nums[l] <= nums[m]) {
                // cout << "left" << endl;
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                } 
            } else if (nums[m] <= nums[r]) {
                // cout << "right" << endl;
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
        }
        return -1;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int result = s.search(nums, 0);
        cout << result << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int result = s.search(nums, 3);
        cout << result << endl;
    }
    {
        vector<int> nums = {1};
        int result = s.search(nums, 0);
        cout << result << endl;
    }
    
    cout << endl;
    return 0;
}
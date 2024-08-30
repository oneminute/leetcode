/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <utils.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp.back();
    }
    
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3,1};
        show_data_h(nums.begin(), nums.end());
        cout << s.rob(nums) << endl;
    }
    {
        vector<int> nums = {2,7,9,3,1};
        show_data_h(nums.begin(), nums.end());
        cout << s.rob(nums) << endl;
    }
    return 0;
}
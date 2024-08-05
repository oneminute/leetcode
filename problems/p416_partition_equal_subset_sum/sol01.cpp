/*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n: nums) {
            sum += n;
        }
        int mid = (sum + 1) >> 1;

        vector<int> dp(mid + 1, 0);
        for (int i = 0; i <= mid; i++) {
            dp[i] = nums[0] <= i ? nums[0] : 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mid) continue;
            for (int j = mid; j > nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return sum - dp[mid] == dp[mid];
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,5,11,5};
        cout << s.canPartition(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3,5};
        cout << s.canPartition(nums) << endl;
    }
    
    return 0;
}
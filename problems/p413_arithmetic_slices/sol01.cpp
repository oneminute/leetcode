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
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<vector<int>> pd(nums.size(), vector<int>(2, 0));
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                pd[i][0] = pd[i - 1][0] + 1;
            }
            pd[i][1] = pd[i - 1][1] + pd[i][0];
            // cout << i << ", " << pd[i][0] << ", " << pd[i][1] << endl;
        }
        return pd[nums.size() - 1][1];
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3,4};
        show_data_h(nums.begin(), nums.end());
        cout << s.numberOfArithmeticSlices(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3,4,5,6};
        show_data_h(nums.begin(), nums.end());
        cout << s.numberOfArithmeticSlices(nums) << endl;
    }
    {
        vector<int> nums = {1};
        show_data_h(nums.begin(), nums.end());
        cout << s.numberOfArithmeticSlices(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3,4,0,1,2,3,4};
        show_data_h(nums.begin(), nums.end());
        cout << s.numberOfArithmeticSlices(nums) << endl;
    }
    printf("\n");
    return 0;
}
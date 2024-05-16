/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        else if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];
        int l = 0, r = nums.size() - 1;
        int m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] != nums[m + 1] && nums[m] != nums[m - 1]) {
                break;
            } else if (nums[m] == nums[m - 1]) {
                m--;
            }

            if (m & 1 == 1) {
                r = m - 1;
            } else {
                l = m + 2;
            }
        }

        return nums[m];
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        cout << s.singleNonDuplicate(nums) << endl;
    }
    {
        vector<int> nums = {3,3,7,7,10,11,11};
        cout << s.singleNonDuplicate(nums) << endl;
    }

    
    printf("\n");
    return 0;
}
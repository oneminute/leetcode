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
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int m = -1;
        int minNum = nums[0];
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[l] == nums[m]) {
                if (nums[m] < minNum) {
                    minNum = nums[m];
                }
                l++;
            }
            else if (nums[m] == nums[r]) {
                if (nums[m] < minNum) {
                    minNum = nums[m];
                }
                r--;
            }
            else if (nums[l] < nums[m]) {
                if (nums[l] < minNum) {
                    minNum = nums[l];
                }
                l = m + 1;
            } else {
                if (nums[m] < minNum) {
                    minNum = nums[m];
                }
                r = m - 1;
            }
        }
        return minNum;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {3,1};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums = {1,3,5};
        cout << s.findMin(nums) << endl;
    }
    {
        vector<int> nums = {2,2,2,0,1};
        cout << s.findMin(nums) << endl;
    }
    
    printf("\n");
    return 0;
}
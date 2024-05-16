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
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        if (nums.empty())
            return -1;
        int l = s, r = e;
        int m = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == target)
                break;
            else if (target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        return nums[m] == target ? m : -1;
    }

    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m = -1;
        bool found = false;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                found = true;
                break;
            } else {
                if (nums[l] == nums[m]) {
                    l++;
                } else if (nums[r] == nums[m]) {
                    r--;
                } else if (nums[l] < nums[m]) {
                    if (target <= nums[m] && target >= nums[l]) {
                        found = binarySearch(nums, l, m - 1, target) != -1;
                        break;
                    } else {
                        l = m + 1;
                    }
                } else {
                    if (target >= nums[m] && target <= nums[r]) {
                        found = binarySearch(nums, m + 1, r, target) != -1;
                        break;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }

        return found;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int x = 4;
        cout << s.search(nums, x) << endl;
    }
    {
        vector<int> nums = {1,0,1,1,1};
        int x = 0;
        cout << s.search(nums, x) << endl;
    }
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int x = 5;
        cout << s.search(nums, x) << endl;
    }
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int x = 0;
        cout << s.search(nums, x) << endl;
    }
    {
        vector<int> nums = {2,5,6,0,0,1,2};
        int x = 7;
        cout << s.search(nums, x) << endl;
    }
    
    printf("\n");
    return 0;
}
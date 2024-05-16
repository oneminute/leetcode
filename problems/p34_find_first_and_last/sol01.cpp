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
    int binarySearch(vector<int>& nums, int s, int e, int target, int dir) {
        if (nums.size() == 0)
            return -1;

        int l = s, r = e;
        int m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] == target) {
                if (dir == 0) break;
                else if (dir == -1) {
                    if (m > 0 && nums[m - 1] == target)
                        r = m - 1;
                    else
                        break;
                }
                else if (dir == 1) {
                    if (m < e && nums[m + 1] == target)
                        l = m + 1;
                    else
                        break;
                }
            } else if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return nums[m] == target ? m : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int m = binarySearch(nums, 0, nums.size() - 1, target, 0);
        if (m == -1)
            return vector<int> {-1, -1};
        
        int l, r;
        l = binarySearch(nums, 0, m - 1, target, -1);
        r = binarySearch(nums, m + 1, nums.size() - 1, target, 1);
        if (l == -1) l = m;
        if (r == -1) r = m;
        return vector<int> {l, r};
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,1,1,1,1,1,2,3,4,4,5,5,5,6,7,8,8,8,8};
        int target = 8;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    {
        vector<int> nums = {2,2};
        int target = 2;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 6;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    {
        vector<int> nums = {};
        int target = 0;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    {
        vector<int> nums = {1,2,3,3,3,3,4,5,9};
        int target = 3;
        vector<int> pair = s.searchRange(nums, target);
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }
    
    printf("\n");
    return 0;
}

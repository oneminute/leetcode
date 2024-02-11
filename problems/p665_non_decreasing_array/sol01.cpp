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
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }

        vector<int> nums2(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums2[i] = nums[i];
        }

        int count = 0;
        bool left = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                nums[i] = nums[i - 1];
                count++;
                if (count > 1) {
                    left = false;
                    break;
                }
            }
        }
        count = 0;
        bool right = true;
        for (int i = nums2.size() - 2; i >= 0; i--) {
            if (nums2[i] > nums2[i + 1]) {
                nums2[i] = nums2[i + 1];
                count++;
                if (count > 1) {
                    right = false;
                    break;
                }
            }
        }
        return left || right;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {4,2,3};
    // vector<int> nums = {4,2,1};
    // vector<int> nums = {5,7,1,8};
    vector<int> nums = {-1,4,2,3};
    bool possible = s.checkPossibility(nums);
    printf("possible: %d", possible);
    return 0;
}
/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> nums2(nums.size(), 1);
        int l = 0, r = nums.size() - 1;
        for (int n: nums) {
            if (n == 0) {
                nums2[l] = 0;
                l++;
            } else if (n == 2) {
                nums2[r] = 2;
                r--;
            }
        }
        nums = nums2;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {2,0,2,1,1,0};
        s.sortColors(nums);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    
    printf("\n");
    return 0;
}
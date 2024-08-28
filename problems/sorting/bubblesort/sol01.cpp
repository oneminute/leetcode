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
    void bubblesort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size() - i; j++) {
                if (nums[j - 1] > nums[j])
                    swap(nums[j - 1], nums[j]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    show_data_h(nums.begin(), nums.end());
    s.bubblesort(nums);
    show_data_h(nums.begin(), nums.end());
    return 0;
}
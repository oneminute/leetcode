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
    void insertionsort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                    break;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    show_data_h(nums.begin(), nums.end());
    s.insertionsort(nums);
    show_data_h(nums.begin(), nums.end());
    return 0;
}
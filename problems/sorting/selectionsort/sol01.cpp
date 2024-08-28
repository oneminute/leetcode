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
    void selectionsort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int m = i;
            int n = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < n) {
                    n = nums[j];
                    m = j;
                }
            }
            if (m != i)
                swap(nums[i], nums[m]);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    show_data_h(nums.begin(), nums.end());
    s.selectionsort(nums);
    show_data_h(nums.begin(), nums.end());
    return 0;
}
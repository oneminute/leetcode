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
    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        int i = l, j = r;
        int pivot = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= pivot)
                j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot)
                i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        quicksort(nums, l, i); 
        quicksort(nums, i + 1, r);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    show_data_h(nums.begin(), nums.end());
    s.quicksort(nums, 0, nums.size() - 1);
    show_data_h(nums.begin(), nums.end());
    return 0;
}
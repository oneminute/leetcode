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
    void mergesort(vector<int>& nums, int l, int r, vector<int>& temp) {
        if (l >= r)
            return;

        int m = l + (r - l + 1) / 2;
        mergesort(nums, l, m - 1, temp); 
        mergesort(nums, m, r, temp);

        int i = l, j = m;
        int n = l;
        while (i < m || j <= r) {
            if (i >= m)
                temp[n++] = nums[j++];
            else if (j > r)
                temp[n++] = nums[i++];
            else
                if (nums[i] < nums[j])
                    temp[n++] = nums[i++];
                else
                    temp[n++] = nums[j++];
        }

        for (int i = l; i <= r; i++) {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    show_data_h(nums.begin(), nums.end());
    vector<int> temp(nums.size());
    s.mergesort(nums, 0, nums.size() - 1, temp);
    show_data_h(nums.begin(), nums.end());
    return 0;
}
/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pro_result(nums.size(), 1);
        pro_result[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pro_result[i] = pro_result[i - 1] * nums[i - 1];
        }

        int temp = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            temp = temp * nums[i + 1];
            pro_result[i] = pro_result[i] * temp;
        }
        
        return pro_result;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3,4};
        vector<int> result = s.productExceptSelf(nums);
        show_data(result.begin(), result.end());
    }
    {
        vector<int> nums = {-1,1,0,-3,3};
        vector<int> result = s.productExceptSelf(nums);
        show_data(result.begin(), result.end());
    }
    
    cout << endl;
    return 0;
}
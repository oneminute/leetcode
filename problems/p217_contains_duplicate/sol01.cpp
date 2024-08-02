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
    bool containsDuplicate2(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return a < b;
        });
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                return true;
        }
        return false;
    }

    bool containsDuplicate1(vector<int>& nums) {
        unordered_map<int, int> s;
        for (int n: nums) {
            int count = s[n]++;
            if (count > 0) {
                return true;
            }
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicate1(nums);
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3,1};
        cout << s.containsDuplicate(nums) << endl;
    }
    {
        vector<int> nums = {1,2,3,4};
        cout << s.containsDuplicate(nums) << endl;
    }
    {
        vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        cout << s.containsDuplicate(nums) << endl;
    }
    
    cout << endl;
    return 0;
}
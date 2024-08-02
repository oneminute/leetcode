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
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> s;
        for (int n: nums) {
            int count = s[n]++;
            if (count > 0) {
                return true;
            }
        }
        return false;
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
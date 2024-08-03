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
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        vector<vector<int>> results;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            // cout << "i. " << i << endl;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int total = nums[i] + nums[l] + nums[r];
                if (total < 0) {
                    l++;
                } else if (total > 0) {
                    r--;
                } else {
                    results.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (r > l && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return results;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {-1,0,1,2,-1,-4};
        vector<vector<int>> result = s.threeSum(nums);
        for (auto i: result) {
            cout << "[";
            for (auto j: i) {
                cout << j << ",";
            }
            cout << "], ";
        }
        cout << endl;
    }
    
    cout << endl;
    return 0;
}
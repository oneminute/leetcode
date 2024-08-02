/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum3(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            int sub = target - nums[i];
            auto it = hash_map.find(sub);
            if (it != hash_map.end()) {
                return vector<int>{i, it->second};
            }
            hash_map[nums[i]] = i;
        }
        return vector<int>();
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        size_t i = 0, j = indices.size() - 1;
        while (i < j) {
            int sum = nums[indices[i]] + nums[indices[j]];
            // cout << indices[i] << " + " << indices[j] << " = " << sum << ": " << target << endl;
            if (sum == target) {
                cout << "done" << endl;
                return vector<int>{indices[i], indices[j]};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return vector<int>();
    }

    vector<int> twoSum1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{i, j};
                }
            }
        }
        return vector<int> {0, 0};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // return twoSum1(nums, target);
        // return twoSum2(nums, target);
        return twoSum3(nums, target);
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {2,7,11,15};
        vector<int> results = s.twoSum(nums, 9);
        show_data(results.begin(), results.end());
    }
    {
        vector<int> nums = {3,2,4};
        vector<int> results = s.twoSum(nums, 6);
        show_data(results.begin(), results.end());
    }
    {
        vector<int> nums = {3,3};
        vector<int> results = s.twoSum(nums, 6);
        show_data(results.begin(), results.end());
    }
    
    
    cout << endl;
    return 0;
}
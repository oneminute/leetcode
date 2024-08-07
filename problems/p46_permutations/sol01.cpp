/*
 *
 */

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

int dirs[5] = {-1, 0, 1, 0, -1};

class Solution
{
public:
    void dfs(vector<int>& nums, int level, vector<vector<int>>& results) {
        if (level >= nums.size()) {
            results.push_back(nums);
            return;
        }

        for (int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]);
            dfs(nums, level + 1, results);
            swap(nums[i], nums[level]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        dfs(nums, 0, results);
        return results;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,3};
        vector<vector<int>> results = s.permute(nums);
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            int j = 0;
            for (; j < results[i].size() - 1; j++) {
                cout << results[i][j] << ", ";
            }
            cout << results[i][j];
            cout << "]" << endl;
        }
    }
    {
        vector<int> nums = {0,1};
        vector<vector<int>> results = s.permute(nums);
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            int j = 0;
            for (; j < results[i].size() - 1; j++) {
                cout << results[i][j] << ", ";
            }
            cout << results[i][j];
            cout << "]" << endl;
        }
    }
    {
        vector<int> nums = {1};
        vector<vector<int>> results = s.permute(nums);
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            int j = 0;
            for (; j < results[i].size() - 1; j++) {
                cout << results[i][j] << ", ";
            }
            cout << results[i][j];
            cout << "]" << endl;
        }
    }

    printf("\n");
    return 0;
}
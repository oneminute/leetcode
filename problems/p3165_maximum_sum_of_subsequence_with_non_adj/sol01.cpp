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

class Solution
{
public:
    int maxNonAdj(int pos, int end) {
        if (pos >= end) {
            return 0;
        }

        int sum1 = nums[pos] + maxNonAdj(pos + 2, end);
        int sum2 = maxNonAdj(pos + 1, end);
        return max(sum1, sum2);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        table = vector<int>(nums.size(), 0);
        marks = vector<int>(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < 0) nums[i] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (i == 1) {
                table[i] = max(0, nums[i - 1]);
                marks[i] = 1;
            } else {
                if (table[i - 1] + nums[i - 1] > table[i - 2]) {
                    table[i] = nums[i - 1] + table[i - 1];
                    marks[i] = -1;
                } else {
                    table[i] = table[i - 2];
                    marks[i] = -2;
                }
            }
        }

        return 0;
    }

private:
    vector<int> nums;
    vector<int> marks;
    vector<int> table;
};

int main()
{
    Solution s;
    // {
    //     vector<vector<int>> queries = {{26,61},{2,-16},{16,-58},{14,-15},{24,2},{32,67},{3,-42},{17,-1},{32,8},{32,-23},{22,37},{30,-14},{0,58},{12,-50},{16,4},{15,-37},{1,-51},{11,7},{8,46},{3,16},{6,18},{5,58},{6,-7},{22,0},{9,49},{31,34},{17,61},{6,28},{4,50},{33,-66},{13,33},{19,46},{4,-31},{16,-34},{25,-6},{12,46},{10,61},{17,67},{32,15},{20,5},{5,-1},{7,-38},{32,-64},{26,30},{0,47},{3,17},{11,2}};
    //     vector<int> nums = {14,-10,-52,-51,58,-57,23,29,-68,42,11,-31,-66,-65,44,-23,67,-53,-52,43,64,-37,16,-23,65,-33,-16,0,-7,26,-62,31,17,69};
    //     int result = s.maximumSumSubsequence(nums, queries);
    //     cout << result << endl << endl;
    // }
    {
        vector<vector<int>> queries = {{4, 0}, {1, 0}};
        vector<int> nums = {0, 3, 3, 3, 1, -2};
        int result = s.maximumSumSubsequence(nums, queries);
        cout << result << endl << endl;
    }
    {
        vector<vector<int>> queries = {{1, -2}, {0, -3}};
        vector<int> nums = {3, 5, 9};
        int result = s.maximumSumSubsequence(nums, queries);
        cout << result << endl << endl;
    }
    {
        vector<vector<int>> queries = {{0, -5}};
        vector<int> nums = {0, -1};
        int result = s.maximumSumSubsequence(nums, queries);
        cout << result << endl << endl;
    }
    

    cout << endl;
    return 0;
}
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
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < grid[i].size(); j++) {
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};
        cout << s.minPathSum(nums) << endl;
    }
    {
        vector<vector<int>> nums = {{1,2,3},{4,5,6}};
        cout << s.minPathSum(nums) << endl;
    }
    
    printf("\n");
    return 0;
}
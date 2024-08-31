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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), INT_MAX - 1));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat[i].size() - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (j < mat[i].size() - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    if (i < mat.size() - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
        return dp;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
        vector<vector<int>> result = s.updateMatrix(mat);
        for (int i = 0; i < result.size(); i++) {
            show_data_h(result[i].begin(), result[i].end());
        }
        cout << "---------------" << endl;
    }
    {
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
        vector<vector<int>> result = s.updateMatrix(mat);
        for (int i = 0; i < result.size(); i++) {
            show_data_h(result[i].begin(), result[i].end());
        }
        cout << "---------------" << endl;
    }
    {
        vector<vector<int>> mat = {
            {1,0,1,1,0,0,1,0,0,1},
            {0,1,1,0,1,0,1,0,1,1},
            {0,0,1,0,1,0,0,1,0,0},
            {1,0,1,0,1,1,1,1,1,1},
            {0,1,0,1,1,0,0,0,0,1},
            {0,0,1,0,1,1,1,0,1,0},
            {0,1,0,1,0,1,0,0,1,1},
            {1,0,0,0,1,1,1,1,0,1},
            {1,1,1,1,1,1,1,0,1,0},
            {1,1,1,1,0,1,0,0,1,1}};
        vector<vector<int>> result = s.updateMatrix(mat);
        for (int i = 0; i < result.size(); i++) {
            show_data_h(result[i].begin(), result[i].end());
        }
        cout << "---------------" << endl;
    }
    
    printf("\n");
    return 0;
}
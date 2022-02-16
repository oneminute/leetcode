/**
 * @file sol01.cpp
 * @author your name (you@domain.com)
 * @brief 
 * reference from https://blog.csdn.net/zhaitianbao/article/details/120303885?utm_source=app&app_version=5.0.0&utm_source=app
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <SimpleTest.h>

using namespace std;
 
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        
        for (int i = 0; i <= text1.size(); i++)
        {
            for (int j = 0; j <= text2.size(); j++)
            {
                if (j == 0 || i == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main(void)
{
    st::LeetCodeTestRunner<int> runner;
    st::LeetCodeTestCase<int> test01("test01", 3, [=]() {
        Solution sol;
        return sol.longestCommonSubsequence("abcde", "ace");
    });
    runner.addTask(&test01);
    st::LeetCodeTestCase<int> test02("test02", 3, [=]() {
        Solution sol;
        return sol.longestCommonSubsequence("abc", "abc");
    });
    runner.addTask(&test02);
    runner.start();
    runner.finish();

    return 0;
}

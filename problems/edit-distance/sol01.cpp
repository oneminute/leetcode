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
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        
        for (int i = 0; i <= word1.size(); i++)
        {
            for (int j = 0; j <= word2.size(); j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

int main(void)
{
    st::LeetCodeTestRunner<int> runner;
    st::LeetCodeTestCase<int> test01("test01", 3, [=]() {
        Solution sol;
        return sol.minDistance("horse", "ros");
    });
    runner.addTask(&test01);
    st::LeetCodeTestCase<int> test02("test02", 3, [=]() {
        Solution sol;
        return sol.minDistance("sunday", "saturday");
    });
    runner.addTask(&test02);
    runner.start();
    runner.finish();

    return 0;
}

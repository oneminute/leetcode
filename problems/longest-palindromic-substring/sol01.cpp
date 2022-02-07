/**
 * 
 * @file sol01.cpp
 * @author 毒舌大叔
 * @brief 
 * 
 * reference from https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 
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

class Solution {
public:
    string longestPalindrome(string s) {
        int strLength = s.size();
        if (strLength < 2) 
            return s;

        int maxLength = 1; // 最长回文子串的长度
        int begin = 0;  // 最长回文子串的位置

        // dp[i][j] 表示对于输入的s来说，从索引i到索引j位置的子串是否是回文串
        vector<vector<int>> dp(strLength, vector<int>(strLength, 0));

        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < strLength; i++) 
            dp[i][i] = 1;

        // 递推开始。从左向右，先判定第一个2字符的子串是否是回文子串。依次增加要判定的回文字串的长度，直到原文字串长度为止
        for (int subLength = 2; subLength <= strLength; subLength++) {
            for (int i = 0; i < strLength - subLength; i++) {
                // 计算子串的右边界
                int j = i + subLength - 1;

                if (s[i] == s[j])   // 如果首尾字符相等
                {
                    if (subLength < 3)  // 如果子串长度小于3 
                    {
                        dp[i][j] = 1;
                    }
                    else    // 如果子串长度大于3，当前子串的回文状态取决于掐头去尾的子串的回文状态
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else    // 首尾字符不相等 
                {
                    dp[i][j] = 0;
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && subLength > maxLength) 
                {
                    maxLength = subLength;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLength);
    }
};

int main()
{
    st::LeetCodeTestRunner<string> runner;
    st::LeetCodeTestCase<string> test01("test01", "a", [=]() {
        Solution sol;
        return sol.longestPalindrome("a");
    });
    runner.addTask(&test01);
    runner.start();
    runner.finish();
}
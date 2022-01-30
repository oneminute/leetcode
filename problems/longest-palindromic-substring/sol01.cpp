#include <iostream>
#include <string>
#include <vector>
#include <SimpleTest.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) 
        {
            return s;
        }

        int maxLen = 1; // 最长回文子串的长度
        int begin = 0;  // 最长回文子串的位置

        // dp[i][j] 表示对于输入的s来说，从索引i到索引j位置的子串是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));

        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) 
        {
            dp[i][i] = true;
        }

        // 递推开始。从左向右，先判定第一个2字符的子串是否是回文子串。依次增加要判定的回文字串的长度，直到原文字串长度为止
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) 
                {
                    break;
                }

                if (s[i] == s[j])   // 如果首尾字符相等
                {
                    if (j - i < 3)  // 如果子串长度小于3 
                    {
                        dp[i][j] = true;
                    }
                    else    // 如果子串长度大于3，当前子串的回文状态取决于掐头去尾的子串的回文状态
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else    // 首尾字符不相等 
                {
                    dp[i][j] = false;
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) 
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int main()
{
    st::LeetCodeTestRunner<string> runner;
    st::LeetCodeTestCase<string> test01("test01", "bab", [=]() {
        Solution sol;
        return sol.longestPalindrome("babad");
    });
    runner.addTask(&test01);
    runner.start();
    runner.finish();
}
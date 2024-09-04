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
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.size(); i++) {
            int n = i - 1;
            int num = stoi(s.substr(n - 1, 2));
            // cout << i << ", " << num << endl;
            if (num == 0 || (num > 20 && num % 10 == 0))
                return 0;
            else if (num < 10 || num > 26) {
                dp[i] = dp[i - 1];
            }
            else if (num == 10 || num == 20) {
                dp[i] = dp[i - 2];
            }
            else {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    {
        cout << s.numDecodings("12") << endl;
    }
    {
        cout << s.numDecodings("226") << endl;
    }
    {
        cout << s.numDecodings("06") << endl;
    }
    {
        cout << s.numDecodings("230") << endl;
    }
    
    printf("\n");
    return 0;
}
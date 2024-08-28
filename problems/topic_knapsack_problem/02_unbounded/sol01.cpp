/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;

int dp[320];
int totalMoney;
int number;

class Solution {
public:
    int maxValue(int C, vector<int> v, vector<int> w) {
        int N = v.size();
        // vector<vector<int>> dp(N, vector<int>(C + 1));
        vector<int> dp(C + 1, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= C; j++) {
                dp[j] = max(dp[j], j >= v[i] ? dp[j - v[i]] + w[i] : 0);
            }
        }

        return dp[C];
    }
};

int main()
{

    Solution s;
    cout << s.maxValue(5, {1,2}, {1,2}) << endl;
    return 0;
}
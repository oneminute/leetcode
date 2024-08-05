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
        for (int i = 0; i <= C; i++) {
            // dp[0][i] = i >= v[0] ? w[0] : 0;
            dp[i] = i >= v[0] ? w[0] : 0;
        }

        for (int i = 1; i < N; i++) {
            for (int j = C; j >= v[i]; j--) {
                int notChoose = dp[j];
                int choose = dp[j - v[i]] + w[i];
                dp[j] = max(notChoose, choose);
            }
        }

        return dp[C];
    }
};

int main()
{

    Solution s;
    cout << s.maxValue(5, {4, 2, 3}, {4, 2, 3}) << endl;
    return 0;
}
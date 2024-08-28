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
        vector<int> dp(C + 1, 0);

        for (int i = 0; i < N; i++) {
            for (int j = C; j >= v[i]; j--) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
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
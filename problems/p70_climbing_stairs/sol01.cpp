/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    int climbing_stairs(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};

int main()
{
    Solution s;
    cout << s.climbing_stairs(3) << endl;
    cout << s.climbing_stairs(4) << endl;
    cout << s.climbing_stairs(100) << endl;
    
    printf("\n");
    return 0;
}
/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> countBits1(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if(i%2) dp[i] = dp[i/2] + 1;
            else dp[i] = dp[i/2];
        }
        return dp;
    }

    vector<int> countBits(int n) {
        vector<int> bits;
        for (int i = 0; i < n + 1; i++) {
            int a = i;
            int count = 0;
            while (a) {
                if (a & 1) count++;
                a >>= 1;
            }
            bits.push_back(count);
        }
        return bits;
    }
};

int main()
{
    Solution s;
    {
        vector<int> results = s.countBits1(11);
        show_data(results.begin(), results.end());
    }
    
    cout << endl;
    return 0;
}
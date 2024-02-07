/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int index = 0;
        for (int i = 1; i <= prices.size(); i++) {
            if (i == prices.size() || prices[i] <= prices[i-1]) {
                int start = index;
                int end = i - 1;
                if (end > start) {
                    profit += prices[end] - prices[start];
                }
                index = i;
            }
        }
        return profit;
    }
};

int main()
{
    Solution s;
    // vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices = {1,2,3,4,5};
    int profit = s.maxProfit(prices);
    printf("profit: %d", profit);
    return 0;
}
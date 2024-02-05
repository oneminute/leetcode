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
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            candies[i] = 1;
            if (ratings[i] > ratings[i-1]) 
                candies[i] = candies[i-1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i] = candies[i+1] + 1;
        }
        int total = 0;
        for (int i = 0; i < candies.size(); i++) {
            total += candies[i];
        }
        return total;
    }
};

int main()
{
    Solution s;
    // vector<int> ratings = {1,0,2};
    // vector<int> ratings = {1,2,2};
    vector<int> ratings = {1,3,4,5,2};
    int total = s.candy(ratings);
    printf("total: %d", total);
    return 0;
}
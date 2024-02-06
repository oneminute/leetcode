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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            int l = 0, c = flowerbed[i], r = 0;
            l = (i - 1) < 0 ? 0 : flowerbed[i - 1];
            r = (i + 1) >= flowerbed.size() ? 0 : flowerbed[i + 1];
            int sum = l + c + r;
            if (sum == 0) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 2;
    bool can = s.canPlaceFlowers(flowerbed, n);
    printf("can: %d", can);
    return 0;
}
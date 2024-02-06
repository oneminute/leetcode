/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <minmax.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [=] (vector<int>& i1, vector<int>& i2) {
            return i1[1] < i2[1];
        });
        for (int i = 0; i < points.size(); i++) {
            printf("[%d, %d]\n", points[i][0], points[i][1]);
        }
        vector<int> overlapping = {0, 0};
        overlapping[0] = points[0][0];
        overlapping[1] = points[0][1];
        int count = 1;
        for (int i = 1; i < points.size(); i++) {
            printf("[%d, %d]\n", overlapping[0], overlapping[1]);
            if (points[i][0] <= overlapping[1]) {
                overlapping[0] = max(points[i][0], overlapping[0]);
                overlapping[1] = min(points[i][1], overlapping[1]);
            } else {
                count++;
                overlapping[0] = points[i][0];
                overlapping[1] = points[i][1];
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{10,16}, {2,8}, {1,6}, {7,12}};
    int arrows = s.findMinArrowShots(points);
    printf("arrows: %d", arrows);
    return 0;
}
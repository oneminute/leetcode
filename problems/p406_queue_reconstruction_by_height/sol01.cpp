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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [=] (vector<int>& i1, vector<int>& i2) {
            return i1[1] < i2[1];
        });
        int count = 0;
        int prev = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev) {
                count++;
            } else {
                prev = intervals[i][1];
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    vector<vector<int>> intervals = {{1,2}, {1,2}, {1,2}};
    int total = s.eraseOverlapIntervals(intervals);
    printf("total: %d", total);
    return 0;
}
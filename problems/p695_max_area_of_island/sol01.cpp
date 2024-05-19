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

class Solution
{
public:
    int dts(vector<vector<int>> &grid, int x, int y) {
        int area = 0;
        stack<pair<int, int>> s; 
        s.push(pair<int, int>(x, y));
        while (!s.empty()) {
            int i = s.top().first;
            int j = s.top().second;
            s.pop();
            area++;
            grid[j][i] = 0;
            if (i + 1 < grid[j].size() && grid[j][i + 1] == 1) {
                grid[j][i + 1] = 2;
                s.push(pair<int, int>(i + 1, j));
            }
            if (i > 0 && grid[j][i - 1] == 1) {
                grid[j][i - 1] = 2;
                s.push(pair<int, int>(i - 1, j));
            }
            if (j + 1 < grid.size() && grid[j + 1][i] == 1) {
                grid[j + 1][i] = 2;
                s.push(pair<int, int>(i, j + 1));
            }
            if (j > 0 && grid[j - 1][i] == 1) {
                grid[j - 1][i] = 2;
                s.push(pair<int, int>(i, j - 1));
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxArea = 0;
        for (int j = 0; j < grid.size(); j++) {
            for (int i = 0; i < grid[j].size(); i++) {
                if (grid[j][i] == 1) {
                    int area = dts(grid, i, j);
                    if (area > maxArea)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
        cout << s.maxAreaOfIsland(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{0,0,0,0,0,0,0,0}};
        cout << s.maxAreaOfIsland(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
        cout << s.maxAreaOfIsland(grid) << endl;
    }

    printf("\n");
    return 0;
}
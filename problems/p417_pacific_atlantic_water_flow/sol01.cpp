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

int dirs[5] = {-1, 0, 1, 0, -1};

class Solution
{
public:
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& marked) {
        stack<pair<int, int>> s;
        s.push(pair<int, int>(x, y));
        while (!s.empty()) {
            int i = s.top().first;
            int j = s.top().second;
            s.pop();
            marked[j][i] = 1;
            int height = heights[j][i];
            for (int d = 0; d < 4; d++) {
                int ii = i + dirs[d];
                int jj = j + dirs[d + 1];
                if (ii < 0 || jj < 0 || jj >= heights.size() || ii >= heights[jj].size() || marked[jj][ii] > 0)
                    continue;
                if (heights[jj][ii] >= height) {
                    s.push(pair<int, int>(ii, jj));
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size());
        vector<vector<int>> atlantic(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            pacific[i].resize(heights[i].size(), 0);
            atlantic[i].resize(heights[i].size(), 0);
        }

        for (int i = 0; i < heights[0].size(); i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, heights.size() - 1, atlantic);
        }

        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, 0, i, pacific);
            dfs(heights, heights[i].size() - 1, i, atlantic);
        }

        vector<vector<int>> paths;
        for (int j = 0; j < heights.size(); j++) {
            for (int i = 0; i < heights[j].size(); i++) {
                if (pacific[j][i] == atlantic[j][i] && pacific[j][i]) {
                    paths.push_back(vector<int> {j, i});
                }
            }
        }
        return paths;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> grid = {{10,10,10},{10,1,10},{10,10,10}};
        vector<vector<int>> paths = s.pacificAtlantic(grid);
        for (int i = 0; i < paths.size(); i++) {
            cout << "[" << paths[i][0] << ", " << paths[i][1] << "]" << endl;
        }
    }
    {
        vector<vector<int>> grid = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
        vector<vector<int>> paths = s.pacificAtlantic(grid);
        for (int i = 0; i < paths.size(); i++) {
            cout << "[" << paths[i][0] << ", " << paths[i][1] << "]" << endl;
        }
    }

    printf("\n");
    return 0;
}
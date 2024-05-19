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
    void dfs(vector<vector<int>>& grid, int k, vector<int>& marked) {
        stack<int> s;
        s.push(k);
        while (!s.empty()) {
            int from = s.top();
            s.pop();
            marked[from] = 1;
            for (int i = 0;i < marked.size(); i++) {
                if (i == from) continue;
                if (grid[from][i] == 1 && marked[i] == 0) {
                    s.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> marked(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if (marked[i] == 0) {
                count++;
                dfs(isConnected, i, marked);
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> grid = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
        cout << s.findCircleNum(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,0,0},{0,1,0},{0,0,1}};
        cout << s.findCircleNum(grid) << endl;
    }
    {
        vector<vector<int>> grid = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
        cout << s.findCircleNum(grid) << endl;
    }

    printf("\n");
    return 0;
}
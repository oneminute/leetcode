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
    void dfs(vector<int>& items, int& level, int index, int n, int k, vector<vector<int>>& results) {
        if (level == k) {
            results.push_back(items);
            return;
        }

        for (int i = index; i <= n; i++) {
            items[level++] = i;
            dfs(items, level, i + 1, n, k, results);
            level--;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> items(k, 0);
        int level = 0;
        dfs(items, level, 1, n, k, results);
        return results;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> results = s.combine(4, 2);
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            int j = 0;
            for (; j < results[i].size() - 1; j++) {
                cout << results[i][j] << ", ";
            }
            cout << results[i][j];
            cout << "]" << endl;
        }
    }
    {
        vector<vector<int>> results = s.combine(1, 1);
        for (int i = 0; i < results.size(); i++) {
            cout << "[";
            int j = 0;
            for (; j < results[i].size() - 1; j++) {
                cout << results[i][j] << ", ";
            }
            cout << results[i][j];
            cout << "]" << endl;
        }
    }

    printf("\n");
    return 0;
}
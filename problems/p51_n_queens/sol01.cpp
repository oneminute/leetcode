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
    void search(vector<vector<string>>& results, vector<string>& result, int n, int count, 
        vector<bool>& rows, vector<bool>& cols, vector<bool>& slash, vector<bool>& bslash) {
        if (count >= n) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < n; i++) {
            int x = i;
            int y = count;
            int slashIndex = x - y + n - 1;
            int bslashIndex = x + y;
            if (rows[y] || cols[x] || slash[slashIndex] || bslash[bslashIndex])
                continue;
            // cout << count << ": " << x << ", " << y << ", " << slashIndex << ", " << bslashIndex << endl;
            
            rows[y] = 1;
            cols[x] = 1;
            slash[slashIndex] = 1;
            bslash[bslashIndex] = 1;
            result[count][i] = 'Q';

            search(results, result, n, count + 1, rows, cols, slash, bslash);

            rows[y] = 0;
            cols[x] = 0;
            slash[slashIndex] = 0;
            bslash[bslashIndex] = 0;
            result[count][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> result(n, string(n, '.'));
        vector<bool> rows(n, false), cols(n, false), slash(n * 2 - 1, false), bslash(n * 2 - 1, false);
        search(results, result, n, 0, rows, cols, slash, bslash);
        return results;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<string>> results = s.solveNQueens(4);
        cout << "---------" << endl;
        for (auto result: results) {
            for (auto line: result) {
                cout << line << endl;
            }
            cout << "+" << endl;
        }
    }
    {
        vector<vector<string>> results = s.solveNQueens(8);
        cout << "---------" << endl;
        for (auto result: results) {
            for (auto line: result) {
                cout << line << endl;
            }
            cout << "+" << endl;
        }
    }
    

    cout << endl;
    return 0;
}
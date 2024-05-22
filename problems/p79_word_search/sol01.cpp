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
    bool dfs(vector<vector<char>>& board, vector<vector<char>>& marks, string& word, int index, int x, int y) {
        // cout << 'word size: ' << word.size() << endl;
        if (index >= word.size() || word[index] != board[y][x] || marks[y][x])
            return false;

        if (index == word.size() - 1)
            return true;

        // cout << board[y][x] << endl;
        bool matched = false;
        marks[y][x] = 1;
        for (int d = 0; d < 4; d++) {
            int i = x + dirs[d];
            int j = y + dirs[d + 1];
            if (i >= 0 && i < board[0].size() && j >= 0 && j < board.size()) {
                // cout << ' sub: ' << i << ', ' << j << endl;
                matched = matched || dfs(board, marks, word, index + 1, i, j);
            }
        }
        marks[y][x] = 0;

        return matched;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> marks(board.size(), vector<char>(board[0].size(), 0));
        for (int j = 0; j < board.size(); j++) {
            for (int i = 0; i < board[0].size(); i++) {
                if (dfs(board, marks, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        string word = "ABCCED";
        bool result = s.exist(grid, word);
        cout << result << endl;
    }
    {
        vector<vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        string word = "SEE";
        bool result = s.exist(grid, word);
        cout << result << endl;
    }
    {
        vector<vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        string word = "ABCB";
        bool result = s.exist(grid, word);
        cout << result << endl;
    }
    

    cout << endl;
    return 0;
}
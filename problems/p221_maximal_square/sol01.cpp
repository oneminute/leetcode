/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <utils.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_length = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') continue;
                int tl = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
                int left = j > 0 ? dp[i][j - 1] : 0;
                int up = i > 0 ? dp[i - 1][j] : 0;
                dp[i][j] = std::min(tl, min(left, up)) + 1;
                max_length = max(max_length, dp[i][j]);
                
            }
        }
        return max_length * max_length;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<char>> mat = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'0','1'},{'1','0'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'0'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'1','1'},{'1','1'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'1','1','0','1'},{'1','1','0','1'},{'1','1','1','1'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    {
        vector<vector<char>> mat = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
        for (int i = 0; i < mat.size(); i++) {
            show_data_h(mat[i].begin(), mat[i].end());
        }
        cout << s.maximalSquare(mat) << endl;
    }
    
    printf("\n");
    return 0;
}
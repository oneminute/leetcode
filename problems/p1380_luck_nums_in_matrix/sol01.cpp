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
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luck_nums;
        vector<int> min_rows(matrix.size());
        vector<int> max_cols(matrix[0].size());
        for (int i = 0; i < min_rows.size(); i++) {
            min_rows[i] = 0;
        }
        for (int i = 0; i < max_cols.size(); i++) {
            max_cols[i] = 0;
        }
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (matrix[r][c] < matrix[r][min_rows[r]]) {
                    min_rows[r] = c;
                }
                if (matrix[r][c] > matrix[max_cols[c]][c]) {
                    max_cols[c] = r;
                }
            }
        }

        for (int i = 0; i < min_rows.size(); i++) {
            if (i == max_cols[min_rows[i]])
                luck_nums.push_back(matrix[i][min_rows[i]]);
        }
        return luck_nums;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> m = {
            { 1,10, 4, 2},
            { 9, 3, 8, 7},
            {15,16,17,12}};
        vector<int> results = s.luckyNumbers(m);
        for (int n: results) {
            cout << n << " " << endl;
        }
    }
    {
        vector<vector<int>> m = {
            { 3, 7, 8},
            { 9,11,13},
            {15,16,17}};
        vector<int> results = s.luckyNumbers(m);
        for (int n: results) {
            cout << n << " " << endl;
        }
    }
    return 0;
}
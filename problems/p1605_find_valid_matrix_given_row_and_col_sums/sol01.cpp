/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <minmax.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(rowSum.size(), vector<int>(colSum.size(), 0));

        for (int i = 0; i < rowSum.size(); i++) {
            for (int j = 0; j < colSum.size(); j++) {
                matrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }

        return matrix;
    }
};

int main()
{
    Solution s;
    vector<int> rowSum1 = {3, 8};
    vector<int> colSum1 = {4, 7};
    vector<int> rowSum2 = {5, 7, 10};
    vector<int> colSum2 = {8, 6, 8};

    vector<vector<int>> matrix1 = s.restoreMatrix(rowSum1, colSum1);
    vector<vector<int>> matrix2 = s.restoreMatrix(rowSum2, colSum2);

    cout << "Matrix 1:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Matrix 2:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
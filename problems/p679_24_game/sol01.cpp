/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:

    bool dfs(vector<double> round) {
        double candidates[6] = {0};
        if (round.size() == 1) {
            return abs(round[0] - 24.0) < 0.0001;
        }

        for (int i = 0; i < round.size() - 1; i++) {
            for (int j = i + 1; j < round.size(); j++) {
                candidates[0] = round[i] + round[j];
                candidates[1] = round[i] - round[j];
                candidates[2] = round[j] - round[i];
                candidates[3] = round[i] * round[j];
                candidates[4] = round[i] / round[j];
                candidates[5] = round[j] / round[i];

                for (int k = 0; k < 6; k++) {
                    if (std::isinf(candidates[k]))
                        continue;
                    vector<double> nextRound(round.size() - 1);
                    int kk = 0;
                    nextRound[kk++] = (candidates[k]);
                    for (int l = 0; l < round.size(); l++) {
                        if (l == i || l == j) continue;
                        nextRound[kk++] = (round[l]);
                    }
                    if (dfs(nextRound))
                        return true;
                }
                
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> round(cards.size());
        for (int i = 0; i < cards.size(); i++) {
            round[i] = cards[i];
        }
        return dfs(round);
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,2,1,2};
        cout << "result: " << s.judgePoint24(nums) << endl;
    }
    {
        vector<int> nums = {1,9,1,2};
        cout << "result: " << s.judgePoint24(nums) << endl;
    }
    {
        vector<int> nums = {4,1,8,7};
        cout << "result: " << s.judgePoint24(nums) << endl;
    }
    
    
    printf("\n");
    return 0;
}

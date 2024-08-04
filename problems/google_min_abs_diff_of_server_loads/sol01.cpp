/*
https://leetcode.com/discuss/interview-question/356433/
There are some processes that need to be executed. Amount of a load that process causes on a server that runs it, is being represented by a single integer. Total load caused on a server is the sum of the loads of all the processes that run on that server. You have at your disposal two servers, on which mentioned processes can be run. Your goal is to distribute given processes between those two servers in the way that, absolute difference of their loads will be minimized.

Given an array of n integers, of which represents loads caused by successive processes, return the minimum absolute difference of server loads.

Example 1:

Input: [1, 2, 3, 4, 5]
Output: 1
Explanation:
We can distribute the processes with loads [1, 2, 4] to the first server and [3, 5] to the second one,
so that their total loads will be 7 and 8, respectively, and the difference of their loads will be equal to 1.
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <utils.h>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
    
    int minAbsDiff(vector<int> loads) {
        int diff = 0;
        int sum = 0;
        for (int n: loads) {
            sum += n;
        }

        int mid = sum / 2;
        if (sum & 1 == 1) {
            mid += 1;
        }

        sort(loads.begin(), loads.end());

        int sum1 = 0;
        for (int i = loads.size() - 1; i >= 0; i--) {
            if (loads[i] + sum1 < mid) {
                sum1 += loads[i];
            }
        }

        diff = abs(sum1 - (sum - sum1));
        return diff;
    }
};

int main()
{
    Solution s;
    cout << s.minAbsDiff({1, 2, 3, 4, 5}) << endl;
    cout << s.minAbsDiff({6,3,4,9,8,2}) << endl;
    
    return 0;
}
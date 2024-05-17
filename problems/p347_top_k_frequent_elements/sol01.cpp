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

struct MyLess {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (int n: nums) {
            table[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyLess> maxHeap;
        for (const auto &p: table) {
            maxHeap.push(p);
        }
        vector<int> results;
        for (int i = 0; i < k; i++) {
            results.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return results;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        vector<int> results = s.topKFrequent(nums, k);
        cout << "------" << endl;
        for (int n: results) {
            cout << n << endl;
        }
    }
    {
        vector<int> nums = {1};
        int k = 1;
        vector<int> results = s.topKFrequent(nums, k);
        cout << "------" << endl;
        for (int n: results) {
            cout << n << endl;
        }
    }
    
    printf("\n");
    return 0;
}
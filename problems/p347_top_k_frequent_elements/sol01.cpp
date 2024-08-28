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
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            num_map[nums[i]]++;
        }
        auto cmp = [&](int a, int b) {
            return num_map[a] < num_map[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> queue(cmp);
        int i = 0;
        for (auto it: num_map) {
            i++;
            queue.push(it.first);
        }
        vector<int> results;
        for (int i = 0; i < k; i++) {
            results.push_back(queue.top());
            queue.pop();
        }
        return results;
    }
    
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
        vector<int> nums = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
        int k = 10;
        vector<int> results = s.topKFrequent(nums, k);
        cout << "------" << endl;
        for (int n: results) {
            cout << n << endl;
        }
    }
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
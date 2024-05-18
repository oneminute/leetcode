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
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int chars[128];
        for (int i = 0; i < 128; i++) {
            chars[i] = 0;
        }

        for (char c: s) {
            chars[c]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, MyLess> queue;
        for (int i = 0; i <= 128; i++) {
            if (chars[i] > 0)
                queue.push(pair<char, int>(i, chars[i]));
        }

        int i = 0;
        while (!queue.empty()) {
            char c = queue.top().first;
            int n = queue.top().second;
            queue.pop();
            for (int j = 0; j < n; i++, j++) {
                s[i] = c;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    {
        string str = "tree";
        string result = s.frequencySort(str);
        cout << str << " --> " << result << endl;
    }
    {
        string str = "cccaaa";
        string result = s.frequencySort(str);
        cout << str << " --> " << result << endl;
    }
    {
        string str = "Aabb";
        string result = s.frequencySort(str);
        cout << str << " --> " << result << endl;
    }
    
    printf("\n");
    return 0;
}
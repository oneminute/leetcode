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
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int p = -1;
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] == '.') {
                v1.push_back(stoi(version1.substr(p + 1, i - p), nullptr, 10));
                p = i;
            } else if (i == version1.size() - 1 && i > p) {
                v1.push_back(stoi(version1.substr(p + 1, i - p), nullptr, 10));
            }
        }
        p = -1;
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] == '.') {
                v2.push_back(stoi(version2.substr(p + 1, i - p), nullptr, 10));
                p = i;
            } else if (i == version2.size() - 1 && i > p) {
                v2.push_back(stoi(version2.substr(p + 1, i - p), nullptr, 10));
            }
        }

        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int n1 = 0, n2 = 0;
            if (i < v1.size())
                n1 = v1[i];
            if (i < v2.size())
                n2 = v2[i];
            if (n1 < n2)
                return -1;
            else if (n1 > n2)
                return 1;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    {
        cout << "result: " << s.compareVersion("1", "0") << endl;
    }
    {
        cout << "result: " << s.compareVersion("1.2", "1.10") << endl;
    }
    {
        cout << "result: " << s.compareVersion("1.01", "1.001") << endl;
    }
    {
        cout << "result: " << s.compareVersion("1.0", "1.0.0.1") << endl;
    }
    
    printf("\n");
    return 0;
}

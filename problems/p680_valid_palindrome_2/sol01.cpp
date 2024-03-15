/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        stack<pair<int, int>> stk;

        int l = 0, r = s.size() - 1;

        int count = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                if (count > 0) {
                    if (stk.empty())
                        return false;
                    pair<int, int> p = stk.top();
                    stk.pop();
                    l = p.first;
                    r = p.second;
                } else {
                    count = 1;
                    stk.push(pair<int, int>(l, r - 1));
                    l++;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    {
        Solution sol;
        string s = "aba";
        printf("result: %d\n", sol.validPalindrome(s));
    }
    {
        Solution sol;
        string s = "abca";
        printf("result: %d\n", sol.validPalindrome(s));
    }
    {
        Solution sol;
        string s = "abc";
        printf("result: %d\n", sol.validPalindrome(s));
    }
    {
        Solution sol;
        string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        printf("result: %d\n", sol.validPalindrome(s));
    }

    return 0;
}
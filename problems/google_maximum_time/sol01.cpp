/*
You are given a string that represents time in the format hh:mm. Some of the digits are blank (represented by ?). Fill in ? such that the time represented by this string is the maximum possible. Maximum time: 23:59, minimum time: 00:00. You can assume that input string is always valid.

Example 1:

Input: "?4:5?"
Output: "14:59"
Example 2:

Input: "23:5?"
Output: "23:59"
Example 3:

Input: "2?:22"
Output: "23:22"
Example 4:

Input: "0?:??"
Output: "09:59"
Example 5:

Input: "??:??"
Output: "23:59"
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
    
    string maximumTime(string s) {
        if (s[0] == '?') {
            if (s[1] == '?' || s[1] <= '3')
                s[0] = '2';
            else
                s[0] = '1';
        }

        if (s[1] == '?') {
            if (s[0] == '2') {
                s[1] = '3';
            } else {
                s[1] = '9';
            }
        }

        if (s[3] == '?') {
            s[3] = '5';
        }

        if (s[4] == '?') {
            s[4] = '9';
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.maximumTime("?4:5?") << endl;
    cout << s.maximumTime("23:5?") << endl;
    cout << s.maximumTime("2?:22") << endl;
    cout << s.maximumTime("0?:??") << endl;
    cout << s.maximumTime("??:??") << endl;
    
    return 0;
}
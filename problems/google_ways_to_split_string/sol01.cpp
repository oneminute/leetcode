/*
https://leetcode.com/discuss/interview-question/553399/
Question 2:
Given a string S, we can split S into 2 strings: S1 and S2. Return the number of ways S can be split such that the number of unique characters between S1 and S2 are the same.

Example 1:

Input: "aaaa"
Output: 3
Explanation: we can get a - aaa, aa - aa, aaa- a
Example 2:

Input: "bac"
Output: 0
Example 3:

Input: "ababa"
Output: 2
Explanation: ab - aba, aba - ba
Looking back on this one I felt like I could've done better and got carried away about how easy I thought it was. I basically, looped from the second element to the second last element, had 2 sets, 1 for each half of the string. and then check if the size of the 2 sets are equal, if so increment a counter. The time complexity is O(n^2) since we have to iterate through the whole string to check of unique characters each time we split. and Space is O(n).
Is there a better way to do this?

Thoughts?
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
    
    int waysToSplitString(string s) {
        unordered_map<char, int> leftMap;
        unordered_map<char, int> rightMap;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            rightMap[s[i]]++;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            leftMap[s[i]]++;
            int t = --rightMap[s[i]];
            if (t == 0) 
                continue;
            if (leftMap.size() != rightMap.size())
                continue;
            auto li = leftMap.begin();
            bool matched = true;
            while (li != leftMap.end()) {
                if (rightMap.find(li->first) == rightMap.end()) {
                    matched = false;
                    break;
                }
                li++;
            }
            if (!matched)
                continue;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.waysToSplitString("aaaa") << endl;
    cout << s.waysToSplitString("bca") << endl;
    cout << s.waysToSplitString("ababa") << endl;
    
    return 0;
}
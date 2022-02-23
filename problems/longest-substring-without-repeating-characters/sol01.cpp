/*
*
* https://leetcode.com/problems/longest-substring-without-repeating-characters/
* Given a string data, find the length of the longest substring without repeating characters.
* 
*
* Example 1:
*
*    Input: data = "abcabcbb"
*    Output: 3
*    Explanation: The answer is "abc", with the length of 3.
*
* Example 2:
*
*    Input: data = "bbbbb"
*    Output: 1
*    Explanation: The answer is "b", with the length of 1.
*
* Example 3:
*
*    Input: data = "pwwkew"
*    Output: 3
*    Explanation: The answer is "wke", with the length of 3.
*    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
* 
*
* Constraints:
*
*    0 <= data.length <= 5 * 104
*    data consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_map>
#include <SimpleTest.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int lookup[128];
        for (int i = 0; i < 128; i++)
            lookup[i] = 0;
        int length = 0;
        int loc = 0;
        for (int i = 0; i < s.size(); i++) {
            loc = max(loc, lookup[s[i]]);
            lookup[s[i]] = i + 1;
            length = max(length, i - loc + 1);
        }
        return length;
    }
};

int main()
{
    st::LeetCodeTestRunner<int> runner;
    st::LeetCodeTestCase<int> test01("test01", 4, [=]() {
        Solution sol;
        return sol.lengthOfLongestSubstring("abcadb");
    });
    runner.addTask(&test01);
    runner.start();
    runner.finish();
}